#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x939d23c1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x52da9824, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd22ce214, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0xb3ac8151, __VMLINUX_SYMBOL_STR(virgo_cloud_set_kernelspace) },
	{ 0xbc04f491, __VMLINUX_SYMBOL_STR(sock_release) },
	{ 0x7adeb8d4, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0xc33ea2fc, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x40ff1d46, __VMLINUX_SYMBOL_STR(kernel_listen) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x69e59c53, __VMLINUX_SYMBOL_STR(virgo_kernel_analytics_conf) },
	{ 0xbecdd3e7, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x39506191, __VMLINUX_SYMBOL_STR(virgo_cloud_get_kernelspace) },
	{ 0x9cc701b9, __VMLINUX_SYMBOL_STR(virgo_cloud_malloc_kernelspace) },
	{ 0xdeb8291b, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0xc32f2bf0, __VMLINUX_SYMBOL_STR(kernel_setsockopt) },
	{ 0x4c62fd7, __VMLINUX_SYMBOL_STR(__memset) },
	{ 0x57d0bb67, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0xa7eedcc4, __VMLINUX_SYMBOL_STR(call_usermodehelper) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x2175cb1, __VMLINUX_SYMBOL_STR(virgo_cloud_free_kernelspace) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x3312365c, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x7ece895f, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xfedfa937, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0x2fb4ff7, __VMLINUX_SYMBOL_STR(kernel_accept) },
	{ 0x93ecf2d5, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0x8fb63660, __VMLINUX_SYMBOL_STR(sock_create) },
	{ 0x90de9ccd, __VMLINUX_SYMBOL_STR(kernel_bind) },
	{ 0x68405e88, __VMLINUX_SYMBOL_STR(skbuff_kernel_socket_debug2) },
	{ 0x783459e8, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0xd6227451, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=virgo_cloud_mempool_kernelspace,virgo_kernel_analytics,virgo_generic_kernelsock_client";


MODULE_INFO(srcversion, "A0C977DE5BB85247F85B4EC");
