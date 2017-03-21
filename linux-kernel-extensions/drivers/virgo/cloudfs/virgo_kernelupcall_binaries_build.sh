#/***************************************************************************************
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
#*****************************************************************************************/


#!/bin/bash

g++ -c virgo_cloud_fs.c 
g++ -o virgo_cloud_fs_main virgo_cloud_fs_main.c
g++ -shared -o libvirgo_fs.so virgo_cloud_fs.o
g++ -c virgo_kernelupcall_plugin.c 
g++ -o virgo_kernelupcall_plugin virgo_kernelupcall_plugin.o -ldl -lpthread
./virgo_kernelupcall_plugin "_Z16virgo_cloud_openPv virgo_cloud_open(/home/kashrinivaasan/linux-3.7.8/drivers/virgo/cloudfs/virgofstest.txt)"
./virgo_kernelupcall_plugin "_Z16virgo_cloud_readPv virgo_cloud_read(3,sssss,256)"
./virgo_kernelupcall_plugin "_Z17virgo_cloud_writePv virgo_cloud_write(3,Appended8May2014,256)"
./virgo_kernelupcall_plugin "_Z17virgo_cloud_closePv virgo_cloud_close(3)"
