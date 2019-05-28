#!/bin/bash
#/***************************************************************************************
#VIRGO - a linux kernel fork-off with machine learning and cloud features 
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
#K.Srinivasan
#NeuronRain Documentation and Licensing: http://neuronrain-documentation.readthedocs.io/en/latest/
#Personal website(research): https://sites.google.com/site/kuja27/
#--------------------------------------------------------------------------------------------------------
#*****************************************************************************************/

#VIRGO BUILD SCRIPT
rm -rf /home/ksrinivasan/linux-5.1.4-build 
mkdir -p /home/ksrinivasan/linux-5.1.4-build 
make -j 4 O=/home/ksrinivasan/linux-5.1.4-build clean 
make mrproper
make -j 4 O=/home/ksrinivasan/linux-5.1.4-build menuconfig 
make -j 4 O=/home/ksrinivasan/linux-5.1.4-build
make -j 4 O=/home/ksrinivasan/linux-5.1.4-build modules_install
make -j 4 O=/home/ksrinivasan/linux-5.1.4-build install
make headers_install
update-initramfs -uvk 5.1.4 
