#
#Makefile for VIRGO mempool cloudexec driver and mempool kernelspace driver for intermodule invocation in kernelspace 
#

KASAN_SANITIZE := n

ccflags-y := -w -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/lib -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/ -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/include -DDEBUG -DLINUX_KERNEL_4_X_X -DVIRGO_KTLS

virgocloudexec_mempool_driver-y := virgo_cloudexec_mempool.o
virgo_cloud_mempool_kernelspace_driver-y := virgo_cloud_mempool_kernelspace.o

obj-m               += virgo_cloudexec_mempool.o virgo_cloud_mempool_kernelspace.o
