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
#include <linux/virgo.h>

static int __init
virgo_cloud_test_kernelspace_init(void)
{
	printk(KERN_INFO "virgo_cloud_test_kernelspace_init(): doing init() of virgo cloud kernel space test module\n");
	return 0;
}
EXPORT_SYMBOL(virgo_cloud_test_kernelspace_init);

int virgo_cloud_test_kernelspace(void* args)
{
	printk(KERN_INFO "virgo_cloud_test_kernelspace(): virgo cloud kernel space test function invoked in this module by virgo_cloudexec kernel service\n");
	return 0;
}
EXPORT_SYMBOL(virgo_cloud_test_kernelspace);


static void __exit
virgo_cloud_test_kernelspace_exit(void)
{
	printk(KERN_INFO "virgo_cloud_test_kernelspace_exit(): exiting virgo cloud test kernel space module \n");
	do_exit(1);
}
EXPORT_SYMBOL(virgo_cloud_test_kernelspace_exit);


MODULE_LICENSE("GPL");
module_init(virgo_cloud_test_kernelspace_init);
module_exit(virgo_cloud_test_kernelspace_exit);
