#
#Makefile for VIRGO eventnet cloudexec driver and eventnet kernelspace driver for intermodule invocation in kernelspace 
#

ccflags-y :=  -w -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/lib -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/ -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/include -DDEBUG -DLINUX_KERNEL_4_x_x

virgocloudexec_eventnet_driver-y := virgo_cloudexec_eventnet.o
virgo_cloud_eventnet_kernelspace_driver-y := virgo_cloud_eventnet_kernelspace.o

obj-m               += virgo_cloudexec_eventnet.o virgo_cloud_eventnet_kernelspace.o
