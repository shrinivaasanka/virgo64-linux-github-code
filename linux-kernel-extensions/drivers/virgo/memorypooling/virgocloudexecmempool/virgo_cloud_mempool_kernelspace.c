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
#include <linux/module.h>
#include <linux/virgo_mempool.h>
#include <linux/string.h>
#include <kstrtox.h>
#include <linux/ctype.h>

unsigned int virgo_parse_integer(const char *s, unsigned int base, unsigned long long *p);
void printBytes(const char* str);
char* toKernelAddress(const char*);
int toInteger(char*);
void* virgo_cloud_malloc_kernelspace(struct virgo_mempool_args*);
void* virgo_cloud_free_kernelspace(struct virgo_mempool_args*);
void* virgo_cloud_get_kernelspace(struct virgo_mempool_args*);
void* virgo_cloud_set_kernelspace(struct virgo_mempool_args*);
struct virgo_mempool_args* parse_virgomempool_command_kernelspace(char* mempoolFunction);

static int __init
virgo_cloud_mempool_kernelspace_init(void)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace_init(): doing init() of virgo cloud kernel space test module\n");
	unsigned long test_ul;
	char* test_str="ef098363";
	kstrtoul(test_str,16,&test_ul);
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace_init(): test_str=%s, test_ul=%u\n",test_str,test_ul);
	return 0;
}
EXPORT_SYMBOL(virgo_cloud_mempool_kernelspace_init);


static void __exit
virgo_cloud_mempool_kernelspace_exit(void)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace_exit(): exiting virgo cloud test kernel space module \n");
	do_exit(1);
}
EXPORT_SYMBOL(virgo_cloud_mempool_kernelspace_exit);



void* virgo_cloud_malloc_kernelspace(struct virgo_mempool_args* args)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:Executing virgo_cloud_mempool on cloud node, Invoking virgo_cloud_malloc_kernelspace(), Writing to file opened by Kernel, Kernel Space to User space communication works\n");
	struct virgo_mempool_args* vmargs=(struct virgo_mempool_args*)args;
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:virgo_cloud_malloc_kernelspace(): size str=%s\n",vmargs->mempool_args[0]);

	int size=toInteger(vmargs->mempool_args[0]);
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:virgo_cloud_malloc_kernelspace(): size=%d\n",size);
	void* ptr=kmalloc(size,GFP_ATOMIC);
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:virgo_cloud_malloc_kernelspace(): ptr=%p\n",ptr);
	vmargs->ptr=(char*)ptr;
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:virgo_cloud_malloc_kernelspace(): setting ptr=%p in vmargs as an out arg\n",ptr);
	return ptr;
}
EXPORT_SYMBOL(virgo_cloud_malloc_kernelspace);

void* virgo_cloud_get_kernelspace(struct virgo_mempool_args* args)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:Executing virgo_cloud_mempool on cloud node, Invoking virgo_cloud_get_kernelspace(), Writing to file opened by Kernel, Kernel Space to User space communication works\n");
	struct virgo_mempool_args* vmargs=args;
	char* ptr=toKernelAddress(vmargs->mempool_args[0]);	
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c: virgo_cloud_get_kernelspace(): data at ptr parsed by toKernelAddress() = [%s]\n",ptr);
	char virgodata_prefix[500];
	strcpy(virgodata_prefix,"virgodata:");
	char* data;
	if(ptr)
	{
		data=kstrdup(strcat(virgodata_prefix,ptr),GFP_ATOMIC);
		printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c: virgo_cloud_get_kernelspace(): address=%p, data=%s, data with added prefix=%s\n",ptr,ptr,data);
	}
	else
	{
		printk(KERN_INFO "virgo_cloud_get_kernelspace(): toKernelAddress() returned NULL\n");
	}
	return data;
}
EXPORT_SYMBOL(virgo_cloud_get_kernelspace);

void* virgo_cloud_set_kernelspace(struct virgo_mempool_args* args)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:Executing virgo_cloud_mempool on cloud node, Invoking virgo_cloud_set_kernelspace(), Writing to file opened by Kernel, Kernel Space to User space communication works\n");
	struct virgo_mempool_args* vmargs=args;
	printk(KERN_INFO "virgo_cloud_set_kernelspace(): vmargs->mempool_cmd=%s, vmargs->mempool_args[0] = %s\n, vmargs->mempool_args[1]=%s \n",vmargs->mempool_cmd, vmargs->mempool_args[0],vmargs->mempool_args[1]);
	char* address=toKernelAddress(vmargs->mempool_args[0]);
	/***********************toKernelAddress()******************************************
	unsigned long ull;
	char* mempool_args_dup=kstrdup(vmargs->mempool_args[0],GFP_ATOMIC);
	mempool_args_dup=kstrdup(strcat(mempool_args_dup,"\n\0"),GFP_ATOMIC);
        kstrtoul(mempool_args_dup,0,&ull);
        void* voidptr_ull=(void*)ull;
        printk(KERN_INFO "virgo_cloud_set_kernelspace(): kstrtoull: ull=%u, (void*)ull=%p,vmargs->mempool_args[0]=[%s],mempool_args_dup=[%s]", ull, voidptr_ull, vmargs->mempool_args[0],mempool_args_dup);
	*********************************************************************************/
	printk(KERN_INFO "virgo_cloud_set_kernelspace(): address set by toKernelAddress=%p\n",address);
	
	/*
	To differentiate address from data a special prefix virgodata: is prepended to data retrieved
	This will be removed by virgo_cloudexec_send_to() module op and only data will be sent to client.
	Similar prefix can also be done for address but for the timebeing one prefix is enough to
	distinguish address and data.
	- Ka.Shrinivaasan 7November2013
	*/
	char* ptr=address;
	if(ptr && vmargs)
	{
		strcpy(ptr,kstrdup(vmargs->mempool_args[1],GFP_ATOMIC));
		printk(KERN_INFO "virgo_cloud_set_kernelspace(): address=%p, data to be set=%s, data pointed to after set=%s\n",address,vmargs->mempool_args[1], ptr);
	}
	else
	{
		if(!ptr)
		{
			printk(KERN_INFO "virgo_cloud_set_kernelspace(): toKernelAddress() returned NULL\n");
		}
		else
		{
			printk(KERN_INFO "virgo_cloud_set_kernelspace(): vmargs is NULL\n");
		}
	}
	return ptr;
}
EXPORT_SYMBOL(virgo_cloud_set_kernelspace);

void* virgo_cloud_free_kernelspace(struct virgo_mempool_args* args)
{
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c:Executing virgo_cloud_mempool on cloud node, Invoking virgo_cloud_free_kernelspace(), Writing to file opened by Kernel, Kernel Space to User space communication works\n");
	struct virgo_mempool_args* vmargs=(struct virgo_mempool_args*)args;
	char* ptr=toKernelAddress(vmargs->mempool_args[0]);
	printk(KERN_INFO "virgo_cloud_mempool_kernelspace.c: virgo_cloud_free_kernelspace(): address=%p\n",ptr);
	kfree(ptr);
	return 0;
}
EXPORT_SYMBOL(virgo_cloud_free_kernelspace);


/*
This function parses the address within the string strAddress and returns as the kernel address
Example: "0x0000ffff" to 0x0000ffff
*/

inline char* toKernelAddress(const char* strAddress)
{
	char *ptr=NULL;

	/*
	char* strAddress1=kmalloc(50,GFP_ATOMIC);
	char* strAddress2=kmalloc(50,GFP_ATOMIC);
	memcpy(strAddress1,strAddress,50);
	memcpy(strAddress2,strAddress,50);
	sscanf(strAddress1,"%p",(void**)&ptr);	
        printk(KERN_INFO "toKernelAddress(): sscanf: strAddress1=[%s], ptr = %p\n", strAddress1, ptr);

	added simple_strtoll() as done in virgo_malloc.c syscall client
	as sscanf returns null similar to virgo_malloc.c.
	simple_strtoul() is sscanf internal call which is deeper than sscanf.
	- Ka.Shrinivaasan 25October2013, 31October2013
	const char* endptr;
        printk(KERN_INFO "toKernelAddress(): before simple_strtoll: strAddress=[%s]\n",strAddress);
        unsigned long ll1=simple_strtoll(strAddress, &endptr, 16);
	void* voidptr_ll1=(void*)ll1;
        printk(KERN_INFO "toKernelAddress(): after simple_strtoll: strAddress=[%s], (void*)ll1=%p, ll1=%u\n", strAddress, voidptr_ll1, ll1);

	unsigned long ll2;
	kstrtoll(strAddress,16,&ll2);
	void* voidptr_ll2=(void*)ll2;
        printk(KERN_INFO "toKernelAddress(): kstrtoll: ll2=%u, (void*)ll2=%p,strAddress=[%s]", ll2, voidptr_ll2, strAddress);
	*/

	/*
	virgo_parse_integer() which is underlying all strtoXXX() functions is
	directly invoked with some modifications to handle quotes. 
	- Ka.Shrinivaasan 6November2013
	*/
	unsigned long long ll3;
	virgo_parse_integer(strAddress,16,&ll3);
	printk(KERN_INFO "toKernelAddress(): virgo_parse_integer: ll3=%ld, (char*)ll3=%p, (void*)ll3=%p, strAddress=[%s]\n", ll3, (char*)ll3, (void*)ll3, strAddress);
	printk(KERN_INFO "toKernelAddress(): virgo_parse_integer: data at (char*)ll3=[%s]\n", (char*)ll3);

	/*
        char* ultovoidptr= (char*)ul;
        printk(KERN_INFO "toKernelAddress(): after cast: kstrtoul: ul=%u, strAddress=[%s], ultovoidptr = %p\n", ul, strAddress, ultovoidptr);
	if(ultovoidptr)
	{
        	return ultovoidptr;
	}
	else
		return ptr;
	*/
	return (char*)ll3;
}
EXPORT_SYMBOL(toKernelAddress);

int toInteger(char* strInt)
{
	int n;
	sscanf(strInt, "%d", &n);
	printk(KERN_INFO "toInteger(): strInt=[%s], integer=%d\n", strInt, n);
	return n;
}

void printBytes(const char* str)
{
	const char* p=str;
	while(*p != '\0')
	{
		printk(KERN_INFO "printBytes(): %c\n",*p);
		p++;
	}
	return;
}

/*
Carried over _parse_integer() from lib/kstrtox.c and modified for VIRGO by
adding an additional if clause for quote and unquote as below. 
Probably this missing clause could be causing the kstrtoll() and simple_strtoll()
which use _parse_integer() internally to randomly return junk addresses.
- Ka.Shrinivaasan 6November2013
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



MODULE_LICENSE("GPL");
module_init(virgo_cloud_mempool_kernelspace_init);
module_exit(virgo_cloud_mempool_kernelspace_exit);
