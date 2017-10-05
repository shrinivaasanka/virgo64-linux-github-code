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

#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <string.h>

struct virgo_address
{
        int node_id;
        struct hostport* hstprt;
        void* addr;
};

struct hostport
{
        char* hostip;
        int port;
};


int main(int argc, char* argv[])
{
	/*
	virgo_malloc(), virgo_set(), virgo_get() and virgo_free() syscalls called by syscall numbers
	- Ka.Shrinivaasan
	*/

	unsigned long long virgo_unique_id;

	/* virgo_malloc */
	/*syscall(384,100,&virgo_unique_id);*/
	syscall(549,100,&virgo_unique_id);
	printf("vuid malloc-ed : %llu \n",virgo_unique_id);

	/* virgo_set */
	char set_data[256];
	strcpy(set_data,"DataSet");
	printf("virgo_set() data to set: %s\n",set_data);
	/*long set_ret=syscall(385,virgo_unique_id,set_data);*/
	long set_ret=syscall(550,virgo_unique_id,set_data);

	/*virgo_get*/
	char get_data[256];
	/*long get_ret=syscall(386,virgo_unique_id,get_data);*/
	long get_ret=syscall(551,virgo_unique_id,get_data);
	printf("virgo_get() data : %s\n",get_data);

	/*virgo_free*/
	/*long free_ret=syscall(387,virgo_unique_id);*/
	long free_ret=syscall(552,virgo_unique_id);
	return 0;
}
