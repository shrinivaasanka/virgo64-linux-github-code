#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

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
	{ 0xb2be4cbd, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xaaef6d9d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0xafcf32c7, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0xb3ac8151, __VMLINUX_SYMBOL_STR(virgo_cloud_set_kernelspace) },
	{ 0x397f129e, __VMLINUX_SYMBOL_STR(skbuff_kernel_socket_debug) },
	{ 0x37932bc7, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0xee11bf7a, __VMLINUX_SYMBOL_STR(kernel_listen) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x69e59c53, __VMLINUX_SYMBOL_STR(virgo_kernel_analytics_conf) },
	{ 0x7843bc0f, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x39506191, __VMLINUX_SYMBOL_STR(virgo_cloud_get_kernelspace) },
	{ 0x9cc701b9, __VMLINUX_SYMBOL_STR(virgo_cloud_malloc_kernelspace) },
	{ 0xe8ef0ff0, __VMLINUX_SYMBOL_STR(current_kernel_time64) },
	{ 0x4fc3b2d0, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0x4c62fd7, __VMLINUX_SYMBOL_STR(__memset) },
	{ 0x66fae6e1, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0xc5fdef94, __VMLINUX_SYMBOL_STR(call_usermodehelper) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x2175cb1, __VMLINUX_SYMBOL_STR(virgo_cloud_free_kernelspace) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xbbb98d54, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x8dd13fa1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x146e4775, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0xcdb5adfc, __VMLINUX_SYMBOL_STR(kernel_accept) },
	{ 0x3e7695d4, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0x4dc5f81f, __VMLINUX_SYMBOL_STR(sock_create) },
	{ 0x24050c72, __VMLINUX_SYMBOL_STR(kernel_bind) },
	{ 0x59fe5d4a, __VMLINUX_SYMBOL_STR(skbuff_kernel_socket_debug2) },
	{ 0xd638be0b, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0x9c3eee67, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=virgo_cloud_mempool_kernelspace,virgo_generic_kernelsock_client    EXPORT_SYMBOL,virgo_kernel_analytics,virgo_generic_kernelsock_client";


MODULE_INFO(srcversion, "C5284FF74611865B9FA250B");
