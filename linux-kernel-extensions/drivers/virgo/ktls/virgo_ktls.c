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

#include <linux/virgo_ktls.h>
#include <linux/string.h>
#include <linux/kallsyms.h>


void read_virgo_ktls_config()
{
	/* virgo_ktls.conf contains key-value pairs of GNUTLS created crypto_info required by kernel transport layer security */

	loff_t bytesread=0;
	loff_t pos=0;
	mm_segment_t fs;

	printk(KERN_INFO "virgo ktls: read_virgo_ktls_config(): virgo_cloud KTLS config being read... \n");
	fs=get_fs();
	set_fs(get_ds());
	struct file* f=NULL;
	f=filp_open("/etc/virgo_ktls.conf", O_RDONLY, 0);

	if(IS_ERR(f))
		printk(KERN_INFO, "read_virgo_ktls_config(): error opening virgo_ktls.conf");

	char buf[3000];
	int i=0;

	int k=0;
	for(k=0;k<256;k++)
		buf[k]=0;


	char* key;
	char* value;

	pos=0;
        if(f !=NULL)
        {
                bytesread=vfs_read(f, buf, 3000, &pos);
                pos=pos+bytesread;
        }
        char* confdelim=",";
	char* keyvaluedelim="=";
        char* confvar=NULL;
        char* bufdup=kstrdup(buf,GFP_KERNEL);
        while(bufdup != NULL)
        {
                confvar=strsep(&bufdup, confdelim);
		char* confvardup=kstrdup(confvar,GFP_ATOMIC);
		char* confkey=strsep(&confvardup, keyvaluedelim);
		char* confvalue=confvardup;	
                virgo_ktls_conf[i].key=kstrdup(confkey,GFP_KERNEL);
                virgo_ktls_conf[i].value=kstrdup(confvalue,GFP_KERNEL);
		printk(KERN_INFO "read_virgo_ktls_config() parsed GNUTLS crypto info variable: %s = %s \n",virgo_ktls_conf[i].key,virgo_ktls_conf[i].value);
                i++;
        }

	set_fs(fs);
	filp_close(f,NULL);	
}
EXPORT_SYMBOL(read_virgo_ktls_config);


static int __init
virgoktls_init(void)
{
	printk(KERN_INFO "virgo_ktls_init(): initializing virgo KTLS kernel module \n");
	printk(KERN_INFO "virgo_ktls_init(): invoking read_virgo_ktls_config()\n");
	read_virgo_ktls_config();

	return 0;
}
EXPORT_SYMBOL(virgoktls_init);

static void __exit
virgoktls_exit(void)
{
	printk(KERN_INFO "exiting virgo KTLS kernel module \n");
	/*filp_close(file_stdout,NULL);*/
	do_exit(1);
}
EXPORT_SYMBOL(virgoktls_exit);


MODULE_LICENSE("GPL");
module_init(virgoktls_init);
module_exit(virgoktls_exit);
