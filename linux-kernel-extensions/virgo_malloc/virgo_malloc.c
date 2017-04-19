/***************************************************************************************
#---------------------------------------------------------------------------------------
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
#----------------------------------------------------------------------------------------
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

#include <linux/virgo_mempool.h>
#include <linux/socket.h>

#define BUF_SIZE 3000

#define PER_NODE_MALLOC_CHUNK_SIZE 1000

int virgomemorypooling_num_cloud_nodes_client;

char* virgomemorypooling_node_ip_addrs_in_cloud_client[3000];

void virgomemorypooling_read_virgo_config_client();


struct hostport* get_least_loaded_hostport_from_cloud_mempool()
{
	/*
	Either a loadtracking algorithm or a pseudorandom generator based loadbalancing algorithm is invoked to
	get the host ip for next virgo_malloc() function kernel thread execution
	*/

	/*char *LBAlgorithm = "Loadtrack";*/
	char *LBAlgorithm = "PRG";
	struct hostport* hopo = kmalloc(sizeof(struct hostport),GFP_ATOMIC);
	if(strcmp(LBAlgorithm, "Loadtrack")==0)
	{
		char* cloud_host = get_host_from_cloud_Loadtrack_mempool();
		hopo->hostip=kstrdup(cloud_host, GFP_ATOMIC);
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_Loadtrack_mempool() returns host ip: %s \n",hopo->hostip);
		hopo->port=30000;
	}
	else if(strcmp(LBAlgorithm, "PRG")==0)
	{
		char* cloud_host = get_host_from_cloud_PRG_mempool();
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_PRG_mempool() - cloud_host(before kstrdup): %s \n",cloud_host);
		hopo->hostip=kstrdup(cloud_host, GFP_ATOMIC);
		printk(KERN_INFO "get_least_loaded_hostport_from_cloud(): get_host_from_cloud_PRG_mempool() returns host ip: %s \n",hopo->hostip);
		hopo->port=30000;
	}
	return hopo;
}

/* 
 Loadtracking algorithm for  nodes in the cloud
*/

char* get_host_from_cloud_Loadtrack_mempool()
{
	return NULL;
}

/*
Pseudorandom number generator based algorithm to distribute virgo_malloc() requests amongst cloud nodes
*/

char* get_host_from_cloud_PRG_mempool()
{
	unsigned int rand_int = get_random_int();
	/* 
	maps a pseudo random integer in range 0 to 2^32-1 to 0 to num_of_cloud_nodes 
	- Ka.Shrinivaasan 12 July 2013

	unsigned int rand_host_id = (virgomemorypooling_num_cloud_nodes_client) * rand_int / (65536-1);
	*/

	/*
	Instead of range mapping, rand_int (mod) virgomemorypooling_num_cloud_nodes_client is also sufficient
	- Ka.Shrinivaasan 12 July 2013
	*/
	unsigned int rand_host_id = rand_int % virgomemorypooling_num_cloud_nodes_client;

	printk(KERN_INFO "get_host_from_cloud_PRG_mempool() - get_random_int() returned %u \n",rand_int);
	printk(KERN_INFO "get_host_from_cloud_PRG_mempool() range mapping for %d cloud nodes(virgomemorypooling_num_cloud_nodes_client) returns random integer %d, host ip(nodes_ip_addrs_in_cloud): %s \n",virgomemorypooling_num_cloud_nodes_client,rand_host_id, virgomemorypooling_node_ip_addrs_in_cloud_client[rand_host_id]);
	return virgomemorypooling_node_ip_addrs_in_cloud_client[rand_host_id];	
	
}


/*asmlinkage char* sys_virgo_get(struct virgo_address* vaddr)*/
asmlinkage long sys_virgo_get(unsigned long long vuid, char __user *data_out)
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
	char iovbuf[BUF_SIZE];
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	mm_segment_t oldfs;

	virgomemorypooling_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	int chunk_size=0;
	int sum_alloc_size=0;

	printk("virgo_get() system call: before virgo_unique_id_to_addr()\n");
	struct virgo_address* vaddr=virgo_unique_id_to_addr(vuid);
	printk("virgo_get() system call: vuid=%ld, virgo address to retrieve data from is vaddr=%p\n",vuid, vaddr);

	sin.sin_family=AF_INET;
	in4_pton(vaddr->hstprt->hostip, strlen(vaddr->hstprt->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(vaddr->hstprt->port);

	char* virgo_get_cmd;
	char* vaddr_addr_str=addr_to_str(vaddr->addr);
	strcpy(tempbuf,"virgo_cloud_get(");
	virgo_get_cmd=strcat(tempbuf,vaddr_addr_str);
	virgo_get_cmd=strcat(tempbuf, ")");
	strcpy(buf,virgo_get_cmd);			

	printk(KERN_INFO "virgo_get() system call: tempbuf=%s, buf=%s, virgo_get_cmd=%s\n",tempbuf,buf,virgo_get_cmd);
	printk(KERN_INFO "virgo_get() system call: iov.iov_base=%s\n",iov.iov_base);

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
	printk(KERN_INFO "virgo_get() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);

	printk(KERN_INFO "virgo_get() syscall: connected kernel client to virgo cloudexec kernel service; iov.iov_base=%s\n ",iov.iov_base);
	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);
	printk(KERN_INFO "virgo_get() syscall: received message: %s \n", iov.iov_base);

	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_get() syscall: le32_to_cpus(buf): %s \n", buf);
	*/

	sock_release(sock);
	printk(KERN_INFO "virgo_get() syscall: virgo_get() client socket_release() invoked\n");
	
	/*long ret=copy_to_user(data_out,buf,strlen(buf));*/
	printk(KERN_INFO "virgo_get() system_call: before data_out memcpy()\n");
	memcpy(data_out,iov.iov_base,strlen(iov.iov_base));
	printk(KERN_INFO "virgo_get() system_call: after data_out memcpy()\n");
	printk(KERN_INFO "virgo_get() syscall:  data_out=%s\n",data_out);
	return 0;
}


asmlinkage long sys_virgo_set(unsigned long long vuid, const char __user *data_in)
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
	char iovbuf[BUF_SIZE];
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	mm_segment_t oldfs;

	virgomemorypooling_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	/*char* buf;*/
	printk(KERN_INFO "virgo_set() system call: before virgo_unique_id_to_addr()\n");	
	struct virgo_address* vaddr=virgo_unique_id_to_addr(vuid);
	printk(KERN_INFO "virgo_set() system call: after virgo_unique_id_to_addr(), vaddr=%p\n", vaddr);
	char data[BUF_SIZE];

	/*
        printk(KERN_INFO "virgo_set() system call: before copy_from_user, data_in=%s\n",data_in);
	printk(KERN_INFO "virgo_set() system call: __builtin_constant_p(BUF_SIZE-1)=%d\n",__builtin_constant_p(BUF_SIZE-1));
	long copyret=copy_from_user((void*)data,(const void __user *)data_in,BUF_SIZE-1);
	printk(KERN_INFO "virgo_set() system call: copy_from_user returned copyret = %ld\n",copyret);
        */

	printk(KERN_INFO "virgo_set() system call: vuid=%llu, virgo address to set is vaddr=%p\n",vuid,vaddr);
	printk(KERN_INFO "virgo_set() system call: vaddr->addr=%p\n",vaddr->addr);
	printk(KERN_INFO "virgo_set() system_call: before memcpy()\n");
	memcpy(data,data_in,sizeof(data));
	printk(KERN_INFO "virgo_set() system_call: after memcpy()\n");
	printk(KERN_INFO "virgo_set() system call: vuid=%llu, data to set=%s\n", vuid, data);
	int chunk_size=0;
	int sum_alloc_size=0;
	sin.sin_family=AF_INET;
	in4_pton(vaddr->hstprt->hostip, strlen(vaddr->hstprt->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(vaddr->hstprt->port);

	char* virgo_set_cmd;
	char* vaddr_addr_str=addr_to_str(vaddr->addr);
	printk(KERN_INFO "virgo_set() system call: vaddr_addr_str=[%s]",vaddr_addr_str);
	/*virgo_set_cmd=kstrdup(strcat("virgo_cloud_set(",vaddr_addr_str),GFP_ATOMIC);*/
	strcpy(tempbuf,"virgo_cloud_set(");
	virgo_set_cmd=strcat(tempbuf,vaddr_addr_str);
	printk(KERN_INFO "virgo_set() system call: 1. virgo_set_cmd=%s",virgo_set_cmd);
	/*virgo_set_cmd=kstrdup(strcat(virgo_set_cmd,","),GFP_ATOMIC);*/
	virgo_set_cmd=strcat(tempbuf,",");
	printk(KERN_INFO "virgo_set() system call: 2. virgo_set_cmd=%s,data=%s",virgo_set_cmd, data);
	/*virgo_set_cmd=kstrdup(strcat(virgo_set_cmd, data),GFP_ATOMIC);*/
	virgo_set_cmd=strcat(tempbuf, data);
	printk(KERN_INFO "virgo_set() system call: 3. virgo_set_cmd=%s",virgo_set_cmd);
	/*virgo_set_cmd=kstrdup(strcat(virgo_set_cmd, ")"),GFP_ATOMIC);*/
	virgo_set_cmd=strcat(tempbuf, ")");
	printk(KERN_INFO "virgo_set() system call: 4. virgo_set_cmd=%s",virgo_set_cmd);
	strcpy(buf,virgo_set_cmd);

	printk(KERN_INFO "virgo_set() system call: tempbuf=%s, buf=%s, virgo_set_cmd = %s\n",tempbuf, buf, virgo_set_cmd);

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
	printk(KERN_INFO "virgo_set() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);

	printk(KERN_INFO "virgo_set() syscall: connected kernel client to virgo cloudexec kernel service; before kernel_sendmsg(): iov.iov_base = %s\n ",iov.iov_base);
	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);
	printk(KERN_INFO "virgo_set() syscall: received message: %s \n", iov.iov_base);

	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_set() syscall: le32_to_cpus(buf): %s \n", buf);
	*/
	sock_release(sock);
	printk(KERN_INFO "virgo_set() syscall: virgo_set() client socket_release() invoked\n");
	/*return buf;*/
	return 0;
}


/*asmlinkage struct virgo_address* sys_virgo_malloc(int size)*/
asmlinkage long sys_virgo_malloc(int size, unsigned long long __user *vuid)
{
	char iovbuf[BUF_SIZE];
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	char *malloc_cmd;
        int sfd, s, j;
        size_t len;
        ssize_t nread;
	struct msghdr msg;
	int error;
	int nr;
	struct kvec iov;
	int no_of_chunks=1;	
	int chunk_size=0;
	int sum_alloc_size=0;
	int i=0;
	int this_allocation_start_entry=next_vtable_entry;
	mm_segment_t oldfs;
	
	virgomemorypooling_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	/*
	Mutex lock and unlock also causes a kernel panic, hence commented as of now
	- Ka.Shrinivaasan 22October2013
	*/
	
	/*mutex_lock(&vtranstable.vtable_fragment_mutex);*/
	while(true)	
	{
		/*char *buf;*/
		struct hostport* leastloadedhostport = get_least_loaded_hostport_from_cloud_mempool();
		struct socket *sock;
		struct sockaddr_in sin;
		if(leastloadedhostport->hostip==NULL)
		{
			printk(KERN_INFO "virgo_malloc() syscall: leastloadedhostport->hostip == NULL, hardcoding it to loopback address");
			leastloadedhostport->hostip="127.0.0.1";
		}
		if(leastloadedhostport->port != 30000)
		{
			printk(KERN_INFO "virgo_malloc() syscall: leastloadedhostport->port != 30000, hardcoding it to 30000");
			leastloadedhostport->port=30000;
		}
		printk(KERN_INFO "virgo_malloc() syscall: leastloadedhostport->port=%d",leastloadedhostport->port);
		printk(KERN_INFO "virgo_malloc() syscall: leastloadedhostport->hostip=%s",leastloadedhostport->hostip);
		in4_pton(leastloadedhostport->hostip, strlen(leastloadedhostport->hostip), &sin.sin_addr.s_addr, '\0',NULL);

		sin.sin_family=AF_INET;
       		sin.sin_port=htons(leastloadedhostport->port);
		printk(KERN_INFO "virgo_malloc() syscall: after in4_pton and htons, leastloadedhostport->hostip=%s, leastloadedhostport->port=%d, sin.sin_addr.s_addr=%x, sin.sin_port=%x\n",leastloadedhostport->hostip,leastloadedhostport->port, sin.sin_addr.s_addr, sin.sin_port);
		printk(KERN_INFO "virgo_malloc() syscall: size=%d, sum_alloc_size=%d \n", size,sum_alloc_size);
	
		if(sum_alloc_size + PER_NODE_MALLOC_CHUNK_SIZE <= size)
		{
			chunk_size=PER_NODE_MALLOC_CHUNK_SIZE;	
			printk(KERN_INFO "1. virgo_malloc() syscall: size=%d, sum_alloc_size=%d, chunk_size=1000",size,sum_alloc_size);
			strcpy(buf,"virgo_cloud_malloc(1000)");			
		}
		else
		{
			chunk_size=size-sum_alloc_size;
			printk(KERN_INFO "2. virgo_malloc() syscall: size=%d, sum_alloc_size=%d, chunk_size==%d",size,sum_alloc_size,chunk_size);
			/* This should not happen and should have broken earlier in the loop*/
			if(chunk_size <= 0) 
			{
				printk(KERN_INFO "virgo_malloc() syscall: size=%d, sum_alloc_size=%d, chunk_size <= 0, but this should not get printed and should have exited earlier",size,sum_alloc_size);
				break;
			}
			strcpy(tempbuf,"virgo_cloud_malloc(");
			char* chunk_size_str=int_to_str(chunk_size);
			malloc_cmd=strcat(tempbuf,chunk_size_str);
			malloc_cmd=strcat(tempbuf, ")");
			strcpy(buf,malloc_cmd);
			printk(KERN_INFO "virgo_malloc() syscall: malloc_cmd=%s, buf=%s, tempbuf=%s",malloc_cmd,buf,tempbuf);
		}

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
		printk(KERN_INFO "virgo_malloc() syscall: created client kernel socket\n");
		kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);

		printk(KERN_INFO "virgo_malloc() syscall: iov.iov_base=%s",iov.iov_base);

		oldfs=get_fs();
		set_fs(KERNEL_DS);
		len = kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
		set_fs(oldfs);

		printk(KERN_INFO "virgo_malloc() syscall: sent len=%d; iov.iov_base=%s, sent message: %s, iovbuf=%s \n", len, iov.iov_base, buf, iovbuf);

		oldfs=get_fs();
		set_fs(KERNEL_DS);
       		len = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
		/*len = sock->ops->recvmsg(sock, &msg, msg_data_left(&msg), msg.msg_flags);*/
		set_fs(oldfs);
		printk(KERN_INFO "virgo_malloc() syscall: recv len=%d \n", len);
		printk(KERN_INFO "virgo_malloc() syscall: received iov.iov_base: %s \n", iov.iov_base);

		/*
		str_to_addr() doesnot work which uses various %p qualifiers.
		Only simple_strtoll() in str_to_addr2() works. But invoking
		both for printing debug info to kern.log
		- Ka.Shrinivaasan 22October2013
		*/	
		/*vtranstable.vtable[next_vtable_entry].addr=(void*)str_to_addr(iov.iov_base);*/
		vtranstable.vtable[next_vtable_entry].addr=str_to_addr2(iov.iov_base);
		
		printk(KERN_INFO "virgo_malloc() syscall: vtranstable.vtable[%d].addr=%p \n", next_vtable_entry, (char*)vtranstable.vtable[next_vtable_entry].addr);
		vtranstable.vtable[next_vtable_entry].node_id=next_vtable_entry;
		vtranstable.vtable[next_vtable_entry].hstprt=leastloadedhostport;
		vtranstable.vtable[next_vtable_entry].cloud_alloc_id=alloc_id;
		vtranstable.vtable[next_vtable_entry].refcount=1;
		vtranstable.fragment_is_disk_persisted=0;

		printk(KERN_INFO "virgo_malloc() syscall: next_vtable_entry=%d, vtranstable.vtable[next_vtable_entry].node_id=%d, vtranstable.vtable[next_vtable_entry].addr=%p, vtranstable.vtable[next_vtable_entry].hstprt->hostip=%s, vtranstable.vtable[next_vtable_entry].hstprt->port=%d \n",next_vtable_entry, vtranstable.vtable[next_vtable_entry].node_id, (char*)vtranstable.vtable[next_vtable_entry].addr, vtranstable.vtable[next_vtable_entry].hstprt->hostip, vtranstable.vtable[next_vtable_entry].hstprt->port);

		/*       
		le32_to_cpus(buf);
		printk(KERN_INFO "virgo_malloc() syscall: le32_to_cpus(buf): %s \n", buf);
		*/

		if(sock)
		{
			sock_release(sock);
			printk(KERN_INFO "virgo_malloc() syscall: virgo_malloc() client socket_release() invoked\n");
		}
		else
			printk(KERN_INFO "virgo_malloc() syscall: sock is NULL\n");

		sum_alloc_size+=chunk_size;
		next_vtable_entry++;
		no_of_chunks++;
		printk(KERN_INFO "virgo_malloc() syscall: size to be allocated = %d, sum_alloc_size = %d \n", size, sum_alloc_size);

		/*
		If sum of sizes of chunks allocated so far is equal to size then break 
		*/
		if(sum_alloc_size == size)
		{
			printk(KERN_INFO "virgo_malloc() syscall: sum_alloc_size == size, breaking while loop\n");
			break;
		}
	}	
	alloc_id++;
        /*mutex_unlock(&vtranstable.vtable_fragment_mutex);*/

	printk(KERN_INFO "virgo_malloc() syscall: returning &(vtranstable.vtable[this_allocation_start_entry]) == %p\n",&(vtranstable.vtable[this_allocation_start_entry]));
	unsigned long long virgo_unique_id=addr_to_virgo_unique_id(&(vtranstable.vtable[this_allocation_start_entry]));
	/*long copy_ret=copy_to_user(vuid,&virgo_unique_id,sizeof(unsigned long));*/
	printk(KERN_INFO "virgo_malloc() system_call: before vuid memcpy()\n");
	memcpy(vuid,&virgo_unique_id,sizeof(unsigned long long));
	printk(KERN_INFO "virgo_malloc() system_call: after vuid memcpy()\n");
	return 0;
}

/*asmlinkage char* sys_virgo_free(struct virgo_address* vaddr)*/
asmlinkage long sys_virgo_free(unsigned long long vuid)
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
	char iovbuf[BUF_SIZE];
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
	/*char* buf;*/
	char* free_cmd;
	mm_segment_t oldfs;

	virgomemorypooling_read_virgo_config_client();
	memset(buf,0,BUF_SIZE);
	struct virgo_address* vaddr=virgo_unique_id_to_addr(vuid);

	sin.sin_family=AF_INET;
	in4_pton(vaddr->hstprt->hostip, strlen(vaddr->hstprt->hostip), &sin.sin_addr.s_addr, '\0',NULL);
       	sin.sin_port=htons(vaddr->hstprt->port);

	char* vaddr_addr_str=addr_to_str(vaddr->addr);
	strcpy(tempbuf,"virgo_cloud_free(");	
	free_cmd=strcat(tempbuf,vaddr_addr_str);
	free_cmd=strcat(tempbuf, ")");
	strcpy(buf,free_cmd);

	printk(KERN_INFO "virgo_free() system call: tempbuf=%d, buf=%s, free_cmd=%s \n",tempbuf, buf, free_cmd);
	printk(KERN_INFO "virgo_free() system call: iov.iov_base=%s\n",iov.iov_base);

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

	strcpy(iov.iov_base,buf);	
	error = sock_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
	printk(KERN_INFO "virgo_free() syscall: created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);

	printk(KERN_INFO "virgo_free() syscall: connected kernel client to virgo cloudexec kernel service\n ");
	printk(KERN_INFO "virgo_free() syscall: sending message: %s \n", iov.iov_base);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);
	printk(KERN_INFO "virgo_free() syscall: sent message: %s \n", iov.iov_base);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len  = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);
	printk(KERN_INFO "virgo_free() syscall: received message: %s \n", iov.iov_base);
	
	/*
	le32_to_cpus(buf);
	printk(KERN_INFO "virgo_free() syscall: le32_to_cpus(buf): %s \n", buf);
	*/
	sock_release(sock);
	printk(KERN_INFO "virgo_free() syscall: virgo_free() client socket_release() invoked\n");
	
	/*return buf;*/
	return 0;
}

char* int_to_str(int n)
{
	char* ret=(char*)kmalloc(50,GFP_ATOMIC);
	sprintf(ret,"%d",n);
	printk(KERN_INFO "int_to_str(): n=%d\n",n);
	printk(KERN_INFO "int_to_str(): ret=[%s]\n",ret);
	return ret;
}

/*char* addr_to_str(char* addr)*/
char* addr_to_str(void* addr)
{
	char* ret=(char*)kmalloc(50,GFP_ATOMIC);
	sprintf(ret,"%p",addr);
	printk(KERN_INFO "addr_to_str(): addr=%p\n",addr);
	printk(KERN_INFO "addr_to_str(): ret=[%s]\n",ret);
	return ret;
}


/*
This function parses the address within the string straddr and returns as the pointer address
Example: "0x0000ffff" to 0x0000ffff
*/
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

/*
carried over from test/sscanftest.c for debugging null sscanf
*/

void var_sscanf(char *str, const char* fmt, ...)
{
        va_list vargs;
        va_start(vargs, fmt);
        vsscanf(str, fmt, vargs);
        va_end(vargs);
}

/*
carried over from test/sscanftest.c for debugging null sscanf
*/

void* str_to_addr2(char* straddr)
{
	/*
        bit of a hack but a nice one when sscanf() doesn't work the way it is expected to be.
        scan the pointer address in string into a unsigned long long and in base 16 and reinterpret cast
        it to void*.
        */
	char* endptr;
        unsigned long long ll=simple_strtoull(straddr, &endptr, 16);
        void* lltovoidptr= (void*)ll;
        printk(KERN_INFO "str_to_addr2(): straddr=[%s], lltovoidptr = %p\n", straddr, lltovoidptr);
	return lltovoidptr;
}

/*
Follwing functions map a machine address to a unique virgo id (VUID)
and inversely map a unique virgo id (VUID) to a machine address. These have
been added to hide and abstract machine address to the userspace programs.

At present only pointer to unsigned long long cast is done and more sophisticated 
Unique ID generation scheme has to be implemented if needed later.

Such a unique id is very much necessary for scalable persistent key-value store.
- Ka.Shrinivaasan 25October2013 
*/
unsigned long long addr_to_virgo_unique_id(struct virgo_address* vaddr)
{
	unsigned long long uvid=(unsigned long long)vaddr;
	printk(KERN_INFO "addr_to_virgo_unique_id(): vaddr=%p, uvid=%llu\n",vaddr,uvid);	
	return uvid;
}

struct virgo_address* virgo_unique_id_to_addr(unsigned long long virgo_unique_id)
{
	struct virgo_address* vaddr=(struct virgo_address*)virgo_unique_id;
	printk(KERN_INFO "virgo_unique_id_to_addr(): vaddr=%p, virgo_unique_id=%llu\n",vaddr,virgo_unique_id);	
	return vaddr;
}


void virgomemorypooling_read_virgo_config_client()
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

	virgomemorypooling_node_ip_addrs_in_cloud_client=(char**)kallsyms_lookup_name("virgomemorypooling_node_ip_addrs_in_cloud_client");
	virgomemorypooling_num_cloud_nodes_client=kallsyms_lookup_name("virgomemorypooling_num_cloud_nodes_client");

	printk(KERN_INFO "virgo kernel service: read_virgo_config(): virgo_client.config being read... \n");
	printk(KERN_INFO "virgo kernel service: read_virgo_config(): virgomemorypooling_num_cloud_nodes_client=%d #### virgomemorypooling_node_ip_addrs_in_cloud_client=%s\n", virgomemorypooling_num_cloud_nodes_client,virgomemorypooling_node_ip_addrs_in_cloud_client);
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

	for(k=0; k < virgomemorypooling_num_cloud_nodes_client; k++)	
		printk(KERN_INFO "virgo kernel service: read_virgo_config(): before reading virgo_client.conf - virgo_cloud ip address - %d: %s\n", k+1, virgomemorypooling_node_ip_addrs_in_cloud_client[k]);

	printk(KERN_INFO "read_virgo_config(): virgo_client.config file being read \n");


	if(f !=NULL)
	{
		/*f->f_op->read(f, buf, sizeof(buf), &f->f_pos);*/
		bytesread=vfs_read(f, buf, 256, &pos);
		/*strcpy(virgomemorypooling_node_ip_addrs_in_cloud_client[i],buf);*/
		printk(KERN_INFO "do_virgo_cloud_init(): virgo_client.config file string of comma separated IPs : %s \n",buf);
		/*printk(KERN_INFO "do_virgo_cloud_init(): virgo_client.config file line %d \n",i);*/
		pos=pos+bytesread;
	}
	/*virgomemorypooling_num_cloud_nodes_client=tokenize_list_of_ip_addrs(buf);*/
	char* delim=",";
	char* token=NULL;
	char* bufdup=kstrdup(buf,GFP_ATOMIC);
	printk(KERN_INFO "tokenize_list_of_ip_addrs(): bufdup = %s\n",bufdup);
	while(bufdup != NULL)
	{
		token=strsep(&bufdup, delim);	
		printk(KERN_INFO "tokenize_list_of_ip_addrs(): %s\n",token);
		virgomemorypooling_node_ip_addrs_in_cloud_client[i]=kstrdup(token,GFP_ATOMIC);
		printk(KERN_INFO "tokenize_list_of_ip_addrs(): virgomemorypooling_node_ip_addrs_in_cloud_client[%d] = %s\n",i,virgomemorypooling_node_ip_addrs_in_cloud_client[i]);
		i++;
	}
	virgomemorypooling_num_cloud_nodes_client=i;
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
		/strcpy(virgomemorypooling_node_ip_addrs_in_cloud_client[i],  token);/
		i++;
	}
	return i;
}
*/

