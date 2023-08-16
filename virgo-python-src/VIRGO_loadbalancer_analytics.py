#-------------------------------------------------------------------------------------------------------
#NEURONRAIN VIRGO64 - Cloud, Machine Learning and Queue augmented Linux Kernel Fork-off (64-bits)
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
#Personal website(research): http://www.krishna-iresearch.org, https://acadpdrafts.readthedocs.io/en/latest/ 
#--------------------------------------------------------------------------------------------------------

import os

def load_stats(): 
    load=open("/proc/loadavg")
    kerlytix_conf=open("/etc/virgo_kernel_analytics.conf","a")
    kerlytix_conf.write(",localhost_load=["+load.read().strip()+"]")

if __name__=="__main__":
    load_stats()
