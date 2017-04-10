#
#Makefile for VIRGO eventnet cloudexec kernelspace client containing utility exported functions for
#EventNet logging
#

ccflags-y :=  -w -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.10.3/lib -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.10.3/ -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.10.3/include -DDEBUG -DLINUX_KERNEL_4_x_x

virgo_generic_kernelsock_client_driver-y := virgo_generic_kernelsock_client.o

obj-m               += virgo_generic_kernelsock_client.o 
