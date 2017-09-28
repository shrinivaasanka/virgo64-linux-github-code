#
#Makefile for VIRGO fs cloudexec driver and fs kernelspace driver for intermodule invocation in kernelspace 
#

ccflags-y :=  -w -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/lib -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/ -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/include -DDEBUG -DVIRGO_KTLS

virgocloudexec_fs_driver-y := virgo_cloudexec_fs.o
virgo_cloud_fs_kernelspace_driver-y := virgo_cloud_fs_kernelspace.o

obj-m               += virgo_cloudexec_fs.o virgo_cloud_fs_kernelspace.o
