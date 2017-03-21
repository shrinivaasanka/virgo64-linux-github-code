#
#Makefile for VIRGO cloudexec driver and cloudexec kernel service
#

ccflags-y := -w -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.10.3/include -DDEBUG

virgocloudexec_driver-y := virgo_cloudexec.o
virgo_cloud_test_kernelspace_driver-y := virgo_cloud_test_kernelspace.o

#obj-m               += virgo_cloudexec.o virgocloudexecsvc.o
obj-m               += virgo_cloudexec.o virgo_cloud_test_kernelspace.o
#virgocloudexec_driver-objs := virgo_cloudexec.c
#obj-m               += virgo_cloudexec.o
