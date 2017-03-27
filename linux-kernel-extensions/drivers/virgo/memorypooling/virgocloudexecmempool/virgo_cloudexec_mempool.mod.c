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
	{ 0x8c7d229d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x1c014116, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0xb3ac8151, __VMLINUX_SYMBOL_STR(virgo_cloud_set_kernelspace) },
	{ 0x3265df4c, __VMLINUX_SYMBOL_STR(sock_release) },
	{ 0xea650725, __VMLINUX_SYMBOL_STR(skbuff_kernel_socket_debug) },
	{ 0xc5e1d22a, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x54b9f8e3, __VMLINUX_SYMBOL_STR(kernel_listen) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x69e59c53, __VMLINUX_SYMBOL_STR(virgo_kernel_analytics_conf) },
	{ 0xba1a2c01, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x39506191, __VMLINUX_SYMBOL_STR(virgo_cloud_get_kernelspace) },
	{ 0x9cc701b9, __VMLINUX_SYMBOL_STR(virgo_cloud_malloc_kernelspace) },
	{ 0xe8ef0ff0, __VMLINUX_SYMBOL_STR(current_kernel_time64) },
	{ 0x44236e33, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0x26c1ef21, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0xc5fdef94, __VMLINUX_SYMBOL_STR(call_usermodehelper) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x2175cb1, __VMLINUX_SYMBOL_STR(virgo_cloud_free_kernelspace) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x40d2021a, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xd03ea551, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x3b342717, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0x9c0b6cf6, __VMLINUX_SYMBOL_STR(kernel_accept) },
	{ 0x9c276406, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0x5102ed65, __VMLINUX_SYMBOL_STR(sock_create) },
	{ 0x8548d948, __VMLINUX_SYMBOL_STR(kernel_bind) },
	{ 0x8eed8a60, __VMLINUX_SYMBOL_STR(skbuff_kernel_socket_debug2) },
	{ 0x99cfe70f, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0x7de2deee, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=virgo_cloud_mempool_kernelspace,virgo_generic_kernelsock_client    EXPORT_SYMBOL,virgo_kernel_analytics,virgo_generic_kernelsock_client";


MODULE_INFO(srcversion, "8EE6B9D2A351C56E24CF9B0");
