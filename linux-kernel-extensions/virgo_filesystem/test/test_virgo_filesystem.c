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

#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


struct hostport
{
        char* hostip;
        int port;
};


int main(int argc, char* argv[])
{
	/*
	Testcases for:

	sys_virgo_open(char* filepath);
	sys_virgo_read(long vfsdesc, char __user *data_out, int size, int pos);
	sys_virgo_write(long vfsdesc, const char __user *data_in, int size, int pos);
	sys_virgo_close(long vfsdesc);

	invoked by syscall numbers in arch/x86/syscalls/syscalls_32.tbl
	*/

	/* long vfsdesc = syscall(364,"/var/log/virgo_fs/virgofstest.txt"); */ /* open */
	long vfsdesc = syscall(553,"/var/log/virgo_fs/virgofstest.txt"); /* open */
	printf("test_virgo_filesystem.c: vfsdesc = %ld\n",vfsdesc);
	char data_read[256];

	/* syscall(366,vfsdesc,data_read,250,0); */ /* read */
	syscall(555,vfsdesc,data_read,250,0);  /* read */
	printf("test_virgo_filesystem.c: data_read = %s\n",data_read);

	/* syscall(367,vfsdesc,"test_virgo_filesystem_29September2015",250,0); */ /* write */
	syscall(556,vfsdesc,"test_virgo_filesystem_19April2017",250,0); /* write */

	/* syscall(365,vfsdesc);  */ /* close */
	syscall(554,vfsdesc);  /* close */
	return 0;
}
