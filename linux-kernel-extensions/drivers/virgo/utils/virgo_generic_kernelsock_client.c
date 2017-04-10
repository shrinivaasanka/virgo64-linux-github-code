/***************************************************************************************
#-------------------------------------------------------------------------------------------------------
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
#--------------------------------------------------------------------------------------------------------
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
#--------------------------------------------------------------------------------------------------------
*****************************************************************************************/


#include <linux/string.h>
#include <linux/virgo.h>
#include <linux/module.h>
#include <linux/string.h>
#include <kstrtox.h>
#include <linux/ctype.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>

char *eventnet_kernel_service_host="127.0.0.1";

static int __init
virgo_generic_kernelsock_client_init(void)
{
	printk(KERN_INFO "virgo_generic_kernelsock_client_init(): initialising virgo cloud test kernel space module \n");
	virgo_eventnet_log("virgo_generic_kernelsock_client_init(): sample log message for virgo_eventnet_log() \n");
	return 0;
}
EXPORT_SYMBOL(virgo_generic_kernelsock_client_init);

void skbuff_kernel_socket_debug2(struct socket* sock)
{
	int len=1000;
	int header_len=300;
	int user_data_len=500;
	printk(KERN_INFO "in skbuff_kernel_socket_debug2() \n");
	if(sock)
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock = %x \n",sock);
		if(sock->sk)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk is not NULL : %x \n",sock->sk);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk is NULL \n");
		}
		if(sock->ops)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->ops is not NULL : %x \n", sock->ops);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->ops is NULL : %x \n");
		}
		if(sock->sk->sk_route_caps)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_route_caps is not NULL : %ull \n", sock->sk->sk_route_caps);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_route_caps is NULL \n");
		}
		if(sock->sk->sk_prot)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_prot is not NULL, sock->sk->sk_prot->no_autobind=%d \n",sock->sk->sk_prot->no_autobind);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->prot is NULL \n");
		}
	}
	else
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock is NULL \n");
	}
	if(!sock->sk->sk_send_head)
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_send_head is NULL \n");
	}
	else
	{
		printk(KERN_INFO "initializing sk_buff \n");
		struct sk_buff *skb=sock->sk->sk_send_head;
		printk(KERN_INFO "iterating through the sk buffer queue \n");
		while(skb)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_send_head : %x \n", skb);
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_send_head->head : %s \n", kstrdup(skb->head,GFP_KERNEL));
			printk(KERN_INFO "skbuff_kernel_socket_debug2(): sock->sk->sk_send_head->data : %s \n", kstrdup(skb->data,GFP_KERNEL));
			skb=skb->next;
		}
	}
}
EXPORT_SYMBOL(skbuff_kernel_socket_debug2);


void skbuff_kernel_socket_debug(struct socket* sock)
{
	int len=1000;
	int header_len=300;
	int user_data_len=500;
	printk(KERN_INFO "in skbuff_kernel_socket_debug() \n");
	if(sock)
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug(): sock = %x \n",sock);
		if(sock->sk)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk is not NULL : %x \n",sock->sk);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk is NULL \n");
		}
		if(sock->ops)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->ops is not NULL : %x \n", sock->ops);
		}
		else
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->ops is NULL : %x \n");
		}
			
	}
	else
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug(): sock is NULL \n");
	}
	if(!sock->sk->sk_send_head)
	{
		printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk->sk_send_head is NULL, doing alloc_skb() to sk_send_head \n");
		sock->sk->sk_send_head=alloc_skb(len,GFP_KERNEL);
	}
	else
	{
		printk(KERN_INFO "initializing sk_buff \n");
		struct sk_buff *skb=sock->sk->sk_send_head;
		printk(KERN_INFO "doing skb_reserve() \n");
		skb_reserve(skb,header_len);
		printk(KERN_INFO "doing skb_put() for user_data \n");
		char *user_data=skb_put(skb,user_data_len);
		printk(KERN_INFO "memcpy() user_data\n");
		memcpy(user_data,"skbuff_data_24February2016",user_data_len);
		printk(KERN_INFO "iterating through the sk buffer queue \n");
		while(skb)
		{
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk->sk_send_head : %x \n", skb);
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk->sk_send_head->head : %s \n", kstrdup(skb->head,GFP_KERNEL));
			printk(KERN_INFO "skbuff_kernel_socket_debug(): sock->sk->sk_send_head->data : %s \n", kstrdup(skb->data,GFP_KERNEL));
			skb=skb->next;
		}
	}
}
EXPORT_SYMBOL(skbuff_kernel_socket_debug);

void virgo_eventnet_log(char* logmsg)
{
        char buf[BUF_SIZE];
	char tempbuf[BUF_SIZE];
        int sfd, s, j;
        size_t len;
        ssize_t nread;
	struct msghdr msg;
	int error;
	int nr;
	struct kvec iov;
	mm_segment_t oldfs;

	char* hostip = eventnet_kernel_service_host;
	int port=20000;
	struct socket *sock;
	struct sockaddr_in sin;
	in4_pton(hostip, strlen(hostip), &sin.sin_addr.s_addr, '\0',NULL);
	sin.sin_family=AF_INET;
       	sin.sin_port=htons(port);
	printk(KERN_INFO "eventnet_log() : after in4_pton and htons, hostip=%s, port=%d, sin.sin_addr.s_addr=%x, sin.sin_port=%x\n", hostip, port, sin.sin_addr.s_addr, sin.sin_port);
	strcpy(buf,logmsg);

	iov.iov_base=buf;
	iov.iov_len=strlen(buf);
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
	printk(KERN_INFO "eventnet_log() : created client kernel socket\n");
	kernel_connect(sock, (struct sockaddr*)&sin, sizeof(sin) , 0);
	printk(KERN_INFO "eventnet_log() : connected kernel client to virgo cloudexec EventNet kernel service\n ");

	oldfs=get_fs();
	set_fs(KERNEL_DS);
	len = kernel_sendmsg(sock, &msg, &iov, nr, BUF_SIZE);
	set_fs(oldfs);

	printk(KERN_INFO "eventnet_log() : sent len=%d; iov.iov_base=%s, sent message: %s \n", len, iov.iov_base, buf);

	oldfs=get_fs();
	set_fs(KERNEL_DS);
       	len = kernel_recvmsg(sock, &msg, &iov, nr, BUF_SIZE, msg.msg_flags);
	set_fs(oldfs);

	printk(KERN_INFO "eventnet_log() : recv len=%d; received message buf: [%s] \n", len, buf);
	printk(KERN_INFO "eventnet_log() : received iov.iov_base: %s \n", iov.iov_base);

	le32_to_cpus(buf);
	printk(KERN_INFO "eventnet_log() : le32_to_cpus(buf): %s \n", buf);
	printk(KERN_INFO "eventnet_log() : invoking skbuff utility debug function ... \n");
	skbuff_kernel_socket_debug(sock);

	/*
	Mysteriously sock_release() causes kernel panic repeatedly. Hence commenting this
	temporarily.
	- Ka.Shrinivaasan 22October2013
	*/
	/*
	if(sock)
	{
		sock_release(sock);
		printk(KERN_INFO "eventnet_log() : eventnet_log() client socket_release() invoked\n");
	}
	else
		printk(KERN_INFO "eventnet_log() : sock is NULL\n");
	*/

}
EXPORT_SYMBOL(virgo_eventnet_log);

static void __exit
virgo_generic_kernelsock_client_exit(void)
{
	printk(KERN_INFO "virgo_generic_kernelsock_client_exit(): exiting virgo cloud test kernel space module \n");
	do_exit(1);
}
EXPORT_SYMBOL(virgo_generic_kernelsock_client_exit);

MODULE_LICENSE("GPL");
module_init(virgo_generic_kernelsock_client_init);
module_exit(virgo_generic_kernelsock_client_exit);
