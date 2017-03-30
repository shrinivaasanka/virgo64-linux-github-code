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
	{ 0xafcf32c7, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x73475f93, __VMLINUX_SYMBOL_STR(__asan_handle_no_return) },
	{ 0x2ad9e8e0, __VMLINUX_SYMBOL_STR(sock_create_kern) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x63d6b21f, __VMLINUX_SYMBOL_STR(kernel_connect) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xeb2006be, __VMLINUX_SYMBOL_STR(__asan_unregister_globals) },
	{ 0xfbd0896e, __VMLINUX_SYMBOL_STR(__asan_store8_noabort) },
	{ 0x11c74d95, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x8dcfe1d8, __VMLINUX_SYMBOL_STR(__asan_register_globals) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x3fa0b220, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xaccabc6a, __VMLINUX_SYMBOL_STR(in4_pton) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x146e4775, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0xcfb82bbc, __VMLINUX_SYMBOL_STR(__asan_load1_noabort) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xd257b532, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xfd5d0082, __VMLINUX_SYMBOL_STR(__asan_load8_noabort) },
	{ 0x961155d1, __VMLINUX_SYMBOL_STR(__asan_load4_noabort) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C1545046396641E0B91ADB2");
