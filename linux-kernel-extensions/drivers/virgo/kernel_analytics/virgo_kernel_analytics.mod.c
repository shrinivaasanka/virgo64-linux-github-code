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
	{ 0xd22ce214, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x73475f93, __VMLINUX_SYMBOL_STR(__asan_handle_no_return) },
	{ 0xc33ea2fc, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0xdeb8291b, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0x66f53979, __VMLINUX_SYMBOL_STR(kernel_connect) },
	{ 0x57d0bb67, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xeb2006be, __VMLINUX_SYMBOL_STR(__asan_unregister_globals) },
	{ 0xfbd0896e, __VMLINUX_SYMBOL_STR(__asan_store8_noabort) },
	{ 0x8dcfe1d8, __VMLINUX_SYMBOL_STR(__asan_register_globals) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xaccabc6a, __VMLINUX_SYMBOL_STR(in4_pton) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xfedfa937, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xfb42789d, __VMLINUX_SYMBOL_STR(__asan_store1_noabort) },
	{ 0x8fb63660, __VMLINUX_SYMBOL_STR(sock_create) },
	{ 0xfd5d0082, __VMLINUX_SYMBOL_STR(__asan_load8_noabort) },
	{ 0xd6227451, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "73A2DB92CBAA678ECA068AD");
