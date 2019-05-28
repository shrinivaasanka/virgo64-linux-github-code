#
#Makefile for VIRGO kernel_analytics driver and kernel_analytics kernel service
#

ccflags-y += -w -L/lib/modules/5.1.4/build/fs/ -I/home/ksrinivasan/linux-5.1.4/include -DDEBUG

virgokernel_analytics_driver-y := virgo_kernel_analytics.o

obj-m               += virgo_kernel_analytics.o
