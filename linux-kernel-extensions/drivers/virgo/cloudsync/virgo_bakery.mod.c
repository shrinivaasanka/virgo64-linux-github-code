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
	{ 0xe60eb9af, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x73475f93, __VMLINUX_SYMBOL_STR(__asan_handle_no_return) },
	{ 0x7843bc0f, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xeb2006be, __VMLINUX_SYMBOL_STR(__asan_unregister_globals) },
	{ 0x8dcfe1d8, __VMLINUX_SYMBOL_STR(__asan_register_globals) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x647deba3, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x51f5ea28, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xfd5d0082, __VMLINUX_SYMBOL_STR(__asan_load8_noabort) },
	{ 0x961155d1, __VMLINUX_SYMBOL_STR(__asan_load4_noabort) },
	{ 0xfb137e9a, __VMLINUX_SYMBOL_STR(__asan_store4_noabort) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C99CE1029395130BCD38111");
