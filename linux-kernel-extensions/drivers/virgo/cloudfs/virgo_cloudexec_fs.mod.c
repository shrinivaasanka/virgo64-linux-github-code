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
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x73475f93, __VMLINUX_SYMBOL_STR(__asan_handle_no_return) },
	{ 0xbc04f491, __VMLINUX_SYMBOL_STR(sock_release) },
	{ 0xc33ea2fc, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x13f5e4f9, __VMLINUX_SYMBOL_STR(sock_create_kern) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x40ff1d46, __VMLINUX_SYMBOL_STR(kernel_listen) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0xbecdd3e7, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xdeb8291b, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0xc32f2bf0, __VMLINUX_SYMBOL_STR(kernel_setsockopt) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x57d0bb67, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xaca30e76, __VMLINUX_SYMBOL_STR(virgo_cloud_write_kernelspace) },
	{ 0xeb2006be, __VMLINUX_SYMBOL_STR(__asan_unregister_globals) },
	{ 0x2922e680, __VMLINUX_SYMBOL_STR(virgo_cloud_open_kernelspace) },
	{ 0xa7eedcc4, __VMLINUX_SYMBOL_STR(call_usermodehelper) },
	{ 0xfbd0896e, __VMLINUX_SYMBOL_STR(__asan_store8_noabort) },
	{ 0x3122bf1a, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x8dcfe1d8, __VMLINUX_SYMBOL_STR(__asan_register_globals) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0xb6c37ef3, __VMLINUX_SYMBOL_STR(virgo_cloud_read_kernelspace) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x3312365c, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x7ece895f, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xfedfa937, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0x2fb4ff7, __VMLINUX_SYMBOL_STR(kernel_accept) },
	{ 0x66501a, __VMLINUX_SYMBOL_STR(virgo_cloud_close_kernelspace) },
	{ 0xcfb82bbc, __VMLINUX_SYMBOL_STR(__asan_load1_noabort) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x93ecf2d5, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0xfb42789d, __VMLINUX_SYMBOL_STR(__asan_store1_noabort) },
	{ 0x90de9ccd, __VMLINUX_SYMBOL_STR(kernel_bind) },
	{ 0x86d38e51, __VMLINUX_SYMBOL_STR(__asan_loadN_noabort) },
	{ 0xfd5d0082, __VMLINUX_SYMBOL_STR(__asan_load8_noabort) },
	{ 0x783459e8, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0xd6227451, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=virgo_cloud_fs_kernelspace";


MODULE_INFO(srcversion, "F5CFA0D49F0BB1C808A69DB");
