/***************************************************************************************
#--------------------------------------------------------------------------------------
#NEURONRAIN VIRGO - Cloud, Machine Learning and Queue augmented Linux Kernel Fork-off
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.
#----------------------------------------------------------------------------------------
#Copyleft (Copyright+):
#Srinivasan Kannan (alias) Ka.Shrinivaasan (alias) Shrinivas Kannan
#Ph: 9791499106, 9003082186
#Krishna iResearch Open Source Products Profiles:
#http://sourceforge.net/users/ka_shrinivaasan,
#https://github.com/shrinivaasanka,
#https://www.openhub.net/accounts/ka_shrinivaasan
#Personal website(research): https://sites.google.com/site/kuja27/
#emails: ka.shrinivaasan@gmail.com, shrinivas.kannan@gmail.com,
#kashrinivaasan@live.com
#-----------------------------------------------------------------------------------------
*****************************************************************************************/

#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/inet.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <linux/string.h>
#include <linux/unistd.h>
#include <linux/slab.h>
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <linux/file.h>
#include <linux/freezer.h>
#include <net/sock.h>
#include <net/checksum.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include <net/tcp.h>
#include <net/tcp_states.h>
#include <asm/uaccess.h>
#include <asm/ioctls.h>
#include <trace/events/skb.h>

#include <linux/module.h>
#include <linux/types.h>
#include <linux/uio.h>
#include <linux/unistd.h>
#include <linux/init.h>

#include <linux/random.h>

#include <linux/virgo_fs_syscall.h>
#include <linux/ctype.h>
#include <linux/socket.h>
#include <net/tls.h>

#define BUF_SIZE 3000

#define PER_NODE_MALLOC_CHUNK_SIZE 1000

int virgofs_num_cloud_nodes_client;

char* virgofs_node_ip_addrs_in_cloud_client[3000];

unsigned int virgo_parse_integer(const char *s, unsigned int base, unsigned long long *p);

void virgofs_read_virgo_config_client();


struct hostport* get_least_loaded_hostport_from_cloud_fs()
{
	/*
	Either a loadtracking algorithm or a pseudorandom generator based loadbalancing algorithm is invoked to
	get the host ip for next virgo_open() function kernel thread execution
	*/

	/*char *LBAlgorithm = "Loadtrack";*/
	char *LBAlgorithm = "PRG";
	struct hostport* hopo = kmalloc(sizeof(struct hostport),GFP_ATOMIC);
	if(strcmp(LBAlgorithm, "Loadtrack")==0)
	{
		char* cloud_host = get_host_from_cloud_Loadtrack_fs();
		hopo->hostip=kstrdup(cloud_host, GFP_ATOMIC);
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_Loadtrack_fs() returns host ip: %s \n",hopo->hostip);
		hopo->port=50000;
	}
	else if(strcmp(LBAlgorithm, "PRG")==0)
	{
		char* cloud_host = get_host_from_cloud_PRG_fs();
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_PRG_fs() - cloud_host(before kstrdup): %s \n",cloud_host);
		hopo->hostip=kstrdup(cloud_host, GFP_ATOMIC);
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_PRG_fs() returns host ip: %s \n",hopo->hostip);
		hopo->port=50000;
	}
	return hopo;
}

/* 
 Loadtracking algorithm for  nodes in the cloud
*/

char* get_host_from_cloud_Loadtrack_fs()
{
	return NULL;
}

/*
Pseudorandom number generator based algorithm to distribute virgo_open() requests amongst cloud nodes
*/

char* get_host_from_cloud_PRG_fs()
{
	unsigned int rand_int = get_random_int();
	/* 
	maps a pseudo random integer in range 0 to 2^32-1 to 0 to num_of_cloud_nodes 
	- Ka.Shrinivaasan 12 July 2013

	unsigned int rand_host_id = (virgofs_num_cloud_nodes_client) * rand_int / (65536-1);
	*/

	/*
	Instead of range mapping, rand_int (mod) virgofs_num_cloud_nodes_client is also sufficient
	- Ka.Shrinivaasan 12 July 2013
	*/
	unsigned int rand_host_id = rand_int % virgofs_num_cloud_nodes_client;

	printk(KERN_INFO "get_host_from_cloud_PRG_fs() - get_random_int() returned %u \n",rand_int);
	printk(KERN_INFO "get_host_from_cloud_PRG_fs() range mapping for %d cloud nodes(virgofs_num_cloud_nodes_client) returns random integer %d, host ip(nodes_ip_addrs_in_cloud): %s \n",virgofs_num_cloud_nodes_client,rand_host_id, virgofs_node_ip_addrs_in_cloud_client[rand_host_id]);
	return virgofs_node_ip_addrs_in_cloud_client[rand_host_id];	
	
}


/*asmlinkage char* sys_virgo_get(struct virgo_address* vaddr)*/
asmlinkage long sys_virgo_read(long vfsdesc, char __user *data_out, int size, int pos)
{
	int nr;
	struct kvec iov;
	struct msghdr msg;
	int error;
	struct socket *sock;
	struct sockaddr_in sin;
        int sfd, s, j;
        size_t len;
        ssize_t nread;
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	char iovbuf[BUF_SIZE];
	mm_segment_t oldfs;

	virgofs_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	sin.sin_family=AF_INET;
	struct hostport* leastloadedhostip=get_least_loaded_hostport_from_cloud_fs();
	in4_pton(leastloadedhostip->hostip, strlen(leastloadedhostip->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(leastloadedhostip->port);

	char* virgo_read_cmd;
	strcpy(tempbuf,"virgo_cloud_read(");
	virgo_read_cmd=strcat(tempbuf,long_to_str(vfsdesc));
	virgo_read_cmd=strcat(tempbuf,",");
	virgo_read_cmd=strcat(tempbuf,"\"none\",");
	virgo_read_cmd=strcat(tempbuf,int_to_str_vfs(size));
	virgo_read_cmd=strcat(tempbuf,",");
	virgo_read_cmd=strcat(tempbuf,int_to_str_vfs(pos));
	virgo_read_cmd=strcat(tempbuf, ")");
	strcpy(buf,virgo_read_cmd);			

	printk(KERN_INFO "virgo_read() system call: tempbuf=%s, buf=%s, virgo_read_cmd=%s\n",tempbuf,buf,virgo_read_cmd);
	printk(KERN_INFO "virgo_read() system call: iov.iov_base=%s\n",iov.iov_base);

	iov.iov_base=buf;
	iov.iov_len=BUF_SIZE;
	msg.msg_name = (struct sockaddr *) &sin;
	msg.msg_namelen = sizeof(struct sockaddr);
#ifdef LINUX_KERNEL_4_x_x
                msg.msg_iter.iov = &iov;
#else
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
#endif
	msg.msg_control = NULL;
	msg.msg_controllen = 0;
	msg.msg_flags = MSG_NOSIGNAL;
	nr=1;

	/*strcpy(iov.iov_base,buf);*/	
	error = sock_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
        kernel_setsockopt(sock, SOL_TLS, TLS_TX, "tls", sizeof("tls"));

	printk(KERN_INFO "virgo_read() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);
	printk(KERN_INFO "virgo_read() syscall: connected kernel client to virgo cloudexec kernel service\n ");

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_read() syscall: sent message: %s \n", iovbuf);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_read() syscall: received message: %s \n", iovbuf);

	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_read() syscall: le32_to_cpus(buf): %s \n", buf);
	*/
	sock_release(sock);
	printk(KERN_INFO "virgo_read() syscall: virgo_read() client socket_release() invoked\n");
	
	long ret=copy_to_user(data_out,buf,strlen(buf));
	printk(KERN_INFO "virgo_read() syscall: copy_to_user() returns ret=%u, data_out=%s\n",ret,data_out);
	return ret;
}

asmlinkage long sys_virgo_write(long vfsdesc, char __user *data_in, int size, int pos)
{
	int nr;
	struct kvec iov;
	struct msghdr msg;
	int error;
	struct socket *sock;
	struct sockaddr_in sin;
        int sfd, s, j;
        size_t len;
        ssize_t nread;
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	/*char* buf;*/
	char data[BUF_SIZE];
	char iovbuf[BUF_SIZE];
	mm_segment_t oldfs;

	virgofs_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	printk(KERN_INFO "virgo_write() system_call: before memcpy()\n");
	long ret=copy_from_user(data,data_in,strlen(data_in));
	/*memcpy(data,data_in,sizeof(data)-1);*/
	printk(KERN_INFO "virgo_write() system_call: after memcpy()\n");
	printk(KERN_INFO "virgo_write() system call: data to set=%s\n", data);
	sin.sin_family=AF_INET;
	struct hostport* leastloadedhostip=get_least_loaded_hostport_from_cloud_fs();
	in4_pton(leastloadedhostip->hostip, strlen(leastloadedhostip->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(leastloadedhostip->port);

	char* virgo_write_cmd;
	strcpy(tempbuf,"virgo_cloud_write(");
	virgo_write_cmd=strcat(tempbuf,long_to_str(vfsdesc));
	virgo_write_cmd=strcat(tempbuf,",");
	virgo_write_cmd=strcat(tempbuf,data);
	virgo_write_cmd=strcat(tempbuf,",");
	virgo_write_cmd=strcat(tempbuf,int_to_str_vfs(size));
	virgo_write_cmd=strcat(tempbuf,",");
	virgo_write_cmd=strcat(tempbuf,int_to_str_vfs(pos));
	virgo_write_cmd=strcat(tempbuf, ")");
	strcpy(buf,virgo_write_cmd);

	printk(KERN_INFO "virgo_write() system call: tempbuf=%s, buf=%s, virgo_write_cmd = %s\n",tempbuf, buf, virgo_write_cmd);
	printk(KERN_INFO "virgo_write() system call: iov.iov_base=%s\n",iov.iov_base);

	iov.iov_base=buf;
	iov.iov_len=BUF_SIZE;
	msg.msg_name = (struct sockaddr *) &sin;
	msg.msg_namelen = sizeof(struct sockaddr);
#ifdef LINUX_KERNEL_4_x_x
                msg.msg_iter.iov = &iov;
#else
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
#endif
	msg.msg_control = NULL;
	msg.msg_controllen = 0;
	msg.msg_flags = MSG_NOSIGNAL;
	nr=1;
	
	/*strcpy(iov.iov_base, buf);*/
	error = sock_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
        kernel_setsockopt(sock, SOL_TLS, TLS_TX, "tls", sizeof("tls"));

	printk(KERN_INFO "virgo_write() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);
	printk(KERN_INFO "virgo_write() syscall: connected kernel client to virgo cloudexec kernel service\n ");

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_write() syscall: sent message: %s \n", iov.iov_base);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_write() syscall: received message: %s \n", iov.iov_base);

	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_write() syscall: le32_to_cpus(buf): %s \n", buf);
	*/
	sock_release(sock);
	printk(KERN_INFO "virgo_write() syscall: virgo_write() client socket_release() invoked\n");
	
	/*return buf;*/
	return 0;
}


/*asmlinkage struct virgo_address* sys_virgo_malloc(int size)*/
asmlinkage long sys_virgo_open(char* filepath)
{
	virgofs_read_virgo_config_client();
	int i=0;
	mm_segment_t oldfs;

	/*
	Mutex lock and unlock also causes a kernel panic, hence commented as of now
	- Ka.Shrinivaasan 22October2013
	*/
	
	/*mutex_lock(&vtranstable.vtable_fragment_mutex);*/
	/*char *buf;*/
        char buf[BUF_SIZE];
	char iovbuf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	char *open_cmd;
        int sfd, s, j;
        size_t len;
        ssize_t nread;
	struct msghdr msg;
	int error;
	int nr;
	struct kvec iov;
	struct hostport* leastloadedhostport = get_least_loaded_hostport_from_cloud_fs();
	struct socket *sock;
	struct sockaddr_in sin;
	memset(buf,0,BUF_SIZE);

	if(leastloadedhostport->hostip==NULL)
	{
		printk(KERN_INFO "virgo_open() syscall: leastloadedhostport->hostip == NULL, hardcoding it to loopback address");
		leastloadedhostport->hostip="127.0.0.1";
	}
	if(leastloadedhostport->port != 50000)
	{
		printk(KERN_INFO "virgo_open() syscall: leastloadedhostport->port != 50000, hardcoding it to 50000");
		leastloadedhostport->port=50000;
	}
	printk(KERN_INFO "virgo_open() syscall: leastloadedhostport->port=%d",leastloadedhostport->port);
	printk(KERN_INFO "virgo_open() syscall: leastloadedhostport->hostip=%s",leastloadedhostport->hostip);
	in4_pton(leastloadedhostport->hostip, strlen(leastloadedhostport->hostip), &sin.sin_addr.s_addr, '\0',NULL);
	sin.sin_family=AF_INET;
       	sin.sin_port=htons(leastloadedhostport->port);
	printk(KERN_INFO "virgo_open() syscall: after in4_pton and htons, leastloadedhostport->hostip=%s, leastloadedhostport->port=%d, sin.sin_addr.s_addr=%x, sin.sin_port=%x\n",leastloadedhostport->hostip,leastloadedhostport->port, sin.sin_addr.s_addr, sin.sin_port);
	
	strcpy(tempbuf,"virgo_cloud_open(");
	open_cmd=strcat(tempbuf,filepath);
	open_cmd=strcat(tempbuf, ")");
	strcpy(buf,open_cmd);

	printk(KERN_INFO "virgo_open() syscall: open_cmd=%s, buf=%s, tempbuf=%s",open_cmd,buf,tempbuf);

	printk(KERN_INFO "virgo_open() syscall: buf=%s, open_cmd=%s\n",buf, open_cmd);

	iov.iov_base=buf;
	iov.iov_len=BUF_SIZE;
	printk(KERN_INFO "virgo_open() syscall: iov.iov_base=%s\n",iov.iov_base);
	msg.msg_name = (struct sockaddr *) &sin;
	msg.msg_namelen = sizeof(struct sockaddr);
#ifdef LINUX_KERNEL_4_x_x
                msg.msg_iter.iov = &iov;
#else
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
#endif
	msg.msg_control = NULL;
	msg.msg_controllen = 0;
	msg.msg_flags = MSG_NOSIGNAL;
	nr=1;
	
	/*strcpy(iov.iov_base, buf);*/
	error = sock_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
        kernel_setsockopt(sock, SOL_TLS, TLS_TX, "tls", sizeof("tls"));

	printk(KERN_INFO "virgo_open() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);
	printk(KERN_INFO "virgo_open() syscall: connected kernel client to virgo cloudexec kernel service\n ");

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	len = kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_open() syscall: sent len=%d; iov.iov_base=%s\n", len, iov.iov_base);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_open() syscall: recv len=%d\n", len);
	printk(KERN_INFO "virgo_open() syscall: received iov.iov_base: %s \n", iov.iov_base);

	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_open() syscall: le32_to_cpus(buf): %s \n", buf);
	*/
	if(sock)
	{
		sock_release(sock);
		printk(KERN_INFO "virgo_open() syscall: virgo_open() client socket_release() invoked\n");
	}
	else
		printk(KERN_INFO "virgo_open() syscall: sock is NULL\n");
	
        /*mutex_unlock(&vtranstable.vtable_fragment_mutex);*/
	unsigned long long ret;
        virgo_parse_integer(buf,10,&ret);
	return (long)ret;
}

/*asmlinkage char* sys_virgo_free(struct virgo_address* vaddr)*/
asmlinkage long sys_virgo_close(long vfsdesc)
{
	int nr;
	struct kvec iov;
	struct msghdr msg;
	int error;
	struct socket *sock;
	struct sockaddr_in sin;
        int sfd, s, j;
        size_t len;
        ssize_t nread;
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	char iovbuf[BUF_SIZE];
	/*char* buf;*/
	char* close_cmd;
	mm_segment_t oldfs;

	virgofs_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	sin.sin_family=AF_INET;
	struct hostport* leastloadedhostip=get_least_loaded_hostport_from_cloud_fs();
	in4_pton(leastloadedhostip->hostip, strlen(leastloadedhostip->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(leastloadedhostip->port);

	strcpy(tempbuf,"virgo_cloud_close(");	
	close_cmd=strcat(tempbuf,long_to_str(vfsdesc));
	close_cmd=strcat(tempbuf, ")");
	strcpy(buf,close_cmd);

	printk(KERN_INFO "virgo_close() system call: tempbuf=%d, buf=%s, close_cmd=%s \n",tempbuf, buf, close_cmd);

        iov.iov_base=buf;
	iov.iov_len=BUF_SIZE;
	printk(KERN_INFO "virgo_close() system call: iov.iov_base=%s\n",iov.iov_base);
	msg.msg_name = (struct sockaddr *) &sin;
	msg.msg_namelen = sizeof(struct sockaddr);
#ifdef LINUX_KERNEL_4_x_x
                msg.msg_iter.iov = &iov;
#else
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
#endif
	msg.msg_control = NULL;
	msg.msg_controllen = 0;
	msg.msg_flags = MSG_NOSIGNAL;
	nr=1;
	
	/*strcpy(iov.iov_base, buf);*/
	error = sock_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
        kernel_setsockopt(sock, SOL_TLS, TLS_TX, "tls", sizeof("tls"));

	printk(KERN_INFO "virgo_close() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);
	printk(KERN_INFO "virgo_close() syscall: connected kernel client to virgo cloudexec kernel service\n ");

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_close() syscall: sent message: %s \n", iovbuf);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);

	printk(KERN_INFO "virgo_close() syscall: received message: %s \n", iovbuf);

	/*	
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_close() syscall: le32_to_cpus(buf): %s \n", buf);
	*/

	sock_release(sock);
	printk(KERN_INFO "virgo_close() syscall: virgo_close() client socket_release() invoked\n");
	/*return buf;*/
	return 0;
}

char* int_to_str_vfs(int n)
{
	char* ret=(char*)kmalloc(50,GFP_ATOMIC);
	sprintf(ret,"%d",n);
	printk(KERN_INFO "int_to_str_vfs(): n=%d\n",n);
	printk(KERN_INFO "int_to_str_vfs(): ret=[%s]\n",ret);
	return ret;
}

char* long_to_str(long n)
{
	char* ret=(char*)kmalloc(50,GFP_ATOMIC);
	sprintf(ret,"%ld",n);
	printk(KERN_INFO "long_to_str(): n=%ld\n",n);
	printk(KERN_INFO "long_to_str(): ret=[%s]\n",ret);
	return ret;
}

/*
char* addr_to_str(char* addr)
{
	char* ret=(char*)kmalloc(50,GFP_ATOMIC);
	sprintf(ret,"%p",addr);
	printk(KERN_INFO "addr_to_str(): addr=%p\n",addr);
	printk(KERN_INFO "addr_to_str(): ret=[%s]\n",ret);
	return ret;
}


/
This function parses the address within the string straddr and returns as the pointer address
Example: "0x0000ffff" to 0x0000ffff
/
char* str_to_addr(char* straddr)
{
        char *ptr=NULL;
	void *voidptr=NULL;
	void *voidptr_vargs=NULL;
        sscanf(straddr,"%p",(void**)&ptr);
        sscanf(straddr,"%p",&voidptr);
	var_sscanf(straddr, "%p", (void**)&voidptr_vargs);
        printk(KERN_INFO "str_to_addr(): straddr=[%s], address scanned ptr=%p, address scanned voidptr=%p \n", straddr, ptr, voidptr);
        printk(KERN_INFO "str_to_addr(): after var_sscanf(): straddr=[%s], voidptr_vargs by vsscanf: %p \n", straddr, voidptr_vargs);

	var_sscanf(straddr, "%pK", (void**)&voidptr_vargs);
        printk(KERN_INFO "str_to_addr()pK: straddr=[%s], address scanned ptr=%pK, address scanned voidptr=%pK \n", straddr, ptr, voidptr);
        printk(KERN_INFO "str_to_addr()pK: after var_sscanf(): straddr=[%s], voidptr_vargs by vsscanf: %pK \n", straddr, voidptr_vargs);


	var_sscanf(straddr, "%pF", (void**)&voidptr_vargs);
        printk(KERN_INFO "str_to_addr()pF: straddr=[%s], address scanned ptr=%pF, address scanned voidptr=%pF \n", straddr, ptr, voidptr);
        printk(KERN_INFO "str_to_addr()pF: after var_sscanf(): straddr=[%s], voidptr_vargs by vsscanf: %pF \n", straddr, voidptr_vargs);


	var_sscanf(straddr, "%pS", (void**)&voidptr_vargs);
        printk(KERN_INFO "str_to_addr()pS: straddr=[%s], address scanned ptr=%pS, address scanned voidptr=%pS \n", straddr, ptr, voidptr);
        printk(KERN_INFO "str_to_addr()pS: after var_sscanf(): straddr=[%s], voidptr_vargs by vsscanf: %pS \n", straddr, voidptr_vargs);
        return (char*)voidptr_vargs;
}

/
carried over from test/sscanftest.c for debugging null sscanf
/

void var_sscanf(char *str, const char* fmt, ...)
{
        va_list vargs;
        va_start(vargs, fmt);
        vsscanf(str, fmt, vargs);
        va_end(vargs);
}

/
carried over from test/sscanftest.c for debugging null sscanf
/

char* str_to_addr2(char* straddr)
{
	/
        bit of a hack but a nice one when sscanf() doesn't work the way it is expected to be.
        scan the pointer address in string into a unsigned long and in base 16 and reinterpret cast
        it to void*.
        /
	char* endptr;
        unsigned long ll=simple_strtoll(straddr, &endptr, 16);
        void* lltovoidptr= (void*)ll;
        printk(KERN_INFO "str_to_addr2(): straddr=[%s], lltovoidptr = %p\n", straddr, lltovoidptr);
	return (char*)lltovoidptr;
}
*/

unsigned int virgo_parse_integer(const char *s, unsigned int base, unsigned long long *p)
{
	unsigned long long res;
	unsigned int rv;
	int overflow;

	res = 0;
	rv = 0;
	overflow = 0;
	while (*s) {
		printk(KERN_INFO "virgo_parse_integer(): *s=%c, res=%ld\n",*s, res);
		unsigned int val;
		if(*s=='\"')
		{
			s++;
			continue;
		}
		if ('0' <= *s && *s <= '9')
			val = *s - '0';
		else if ('a' <= tolower(*s) && tolower(*s) <= 'f')
			val = tolower(*s) - 'a' + 10;
		else
			break;

		if (val >= base)
			break;
		/*
		 * Check for overflow only if we are within range of
		 * it in the max base we support (16)
		if (unlikely(res & (~0ull << 60))) {
			if (res > div_u64(ULLONG_MAX - val, base))
				overflow = 1;
		}
		*/
		res = res * base + val;
		rv++;
		s++;
	}
	*p = res;
	return rv;
}


/*
Follwing functions map a machine address to a unique virgo id (UVID)
and inversely map a unique virgo id (VID) to a machine address. These have
been added to hide and abstract machine address to the userspace programs.

At present only pointer to unsigned long cast is done and more sophisticated 
Unique ID generation scheme has to be implemented if 
needed later.

Such a unique id is very much necessary for scalable persistent key-value store.
- Ka.Shrinivaasan 25October2013 
unsigned long addr_to_virgo_unique_id(struct virgo_address* vaddr)
{
	unsigned long uvid=(unsigned long)vaddr;
	printk(KERN_INFO "addr_to_virgo_unique_id(): vaddr=%p, uvid=%u\n",vaddr,uvid);	
	return uvid;
}

struct virgo_address* virgo_unique_id_to_addr(unsigned long virgo_unique_id)
{
	struct virgo_address* vaddr=(struct virgo_address*)virgo_unique_id;
	printk(KERN_INFO "virgo_unique_id_to_addr(): vaddr=%p, virgo_unique_id=%u\n",vaddr,virgo_unique_id);	
	return vaddr;
}
*/


void virgofs_read_virgo_config_client()
{
	/* virgo_client.conf contains a string of comma separated list of IP addresses in the virgo cloud .Read and strtok() it. */

	loff_t bytesread=0;
	loff_t pos=0;
	mm_segment_t fs;

	/*
	 * It is redundant to use kallsyms_lookup for exported symbols for virgo cloud initialization. 
	 * kallsyms_lookup is for non-exported symbols.
	 * 
	 * - Ka.Shrinivaasan 10 July 2013
	 *

	virgofs_node_ip_addrs_in_cloud_client=(char**)kallsyms_lookup_name("virgofs_node_ip_addrs_in_cloud_client");
	virgofs_num_cloud_nodes_client=kallsyms_lookup_name("virgofs_num_cloud_nodes_client");

	printk(KERN_INFO "virgo kernel service: read_virgo_config(): virgo_client.config being read... \n");
	printk(KERN_INFO "virgo kernel service: read_virgo_config(): virgofs_num_cloud_nodes_client=%d #### virgofs_node_ip_addrs_in_cloud_client=%s\n", virgofs_num_cloud_nodes_client,virgofs_node_ip_addrs_in_cloud_client);
	*/

	fs=get_fs();
	set_fs(get_ds());
	struct file* f=NULL;
	f=filp_open("/etc/virgo_client.conf", O_RDONLY, 0);

	char buf[256];
	int i=0;

	int k=0;
	for(k=0;k<256;k++)
		buf[k]=0;

	for(k=0; k < virgofs_num_cloud_nodes_client; k++)	
		printk(KERN_INFO "virgo kernel service: read_virgo_config(): before reading virgo_client.conf - virgo_cloud ip address - %d: %s\n", k+1, virgofs_node_ip_addrs_in_cloud_client[k]);

	printk(KERN_INFO "read_virgo_config(): virgo_client.config file being read \n");


	if(f !=NULL)
	{
		/*f->f_op->read(f, buf, sizeof(buf), &f->f_pos);*/
		bytesread=vfs_read(f, buf, 256, &pos);
		/*strcpy(virgofs_node_ip_addrs_in_cloud_client[i],buf);*/
		printk(KERN_INFO "do_virgo_cloud_init(): virgo_client.config file string of comma separated IPs : %s \n",buf);
		/*printk(KERN_INFO "do_virgo_cloud_init(): virgo_client.config file line %d \n",i);*/
		pos=pos+bytesread;
	}
	/*virgofs_num_cloud_nodes_client=tokenize_list_of_ip_addrs(buf);*/
	char* delim=",";
	char* token=NULL;
	char* bufdup=kstrdup(buf,GFP_ATOMIC);
	printk(KERN_INFO "tokenize_list_of_ip_addrs(): bufdup = %s\n",bufdup);
	while(bufdup != NULL)
	{
		token=strsep(&bufdup, delim);	
		printk(KERN_INFO "tokenize_list_of_ip_addrs(): %s\n",token);
		virgofs_node_ip_addrs_in_cloud_client[i]=kstrdup(token,GFP_ATOMIC);
		printk(KERN_INFO "tokenize_list_of_ip_addrs(): virgofs_node_ip_addrs_in_cloud_client[%d] = %s\n",i,virgofs_node_ip_addrs_in_cloud_client[i]);
		i++;
	}
	virgofs_num_cloud_nodes_client=i;
	set_fs(fs);
	filp_close(f,NULL);	
}

/* 
Above tokenization made into a function - if needed can be used as multipurpose exported function
int tokenize_list_of_ip_addrs(char* buf)
{
	char* delim=",";
	char* token=NULL;
	char* bufdup=kstrdup(buf,GFP_ATOMIC);
	printk(KERN_INFO, "tokenize_list_of_ip_addrs(): bufdup = %s\n",bufdup);
	int i=0;
	while(bufdup != NULL)
	{
		token=strsep(&bufdup, delim);	
		printk(KERN_INFO, "tokenize_list_of_ip_addrs(): %s\n",token);
		/strcpy(virgofs_node_ip_addrs_in_cloud_client[i],  token);/
		i++;
	}
	return i;
}
*/


