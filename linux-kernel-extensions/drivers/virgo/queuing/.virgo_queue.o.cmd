cmd_/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o := gcc -Wp,-MD,/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/.virgo_queue.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/7/include -I/home/ksrinivasan/linux-4.13.3/arch/x86/include -I./arch/x86/include/generated  -I/home/ksrinivasan/linux-4.13.3/include -I./include -I/home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/home/ksrinivasan/linux-4.13.3/include/uapi -I./include/generated/uapi -include /home/ksrinivasan/linux-4.13.3/include/linux/kconfig.h  -I/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing -I/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_CRC32=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_AVX512=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -gdwarf-4 -pg -mfentry -DCC_USING_FENTRY -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -w  -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/lib  -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/  -I/media/ka_shrinivaasan/cbddc062-a016-4828-8780-21bc64cef1e8/linux-4.13.3/include -DDEBUG -fsanitize=kernel-address -fasan-shadow-offset=0xdffffc0000000000 --param asan-stack=1 --param asan-globals=1 --param asan-instrumentation-with-call-threshold=0 -fsanitize-address-use-after-scope  -DMODULE  -DKBUILD_BASENAME='"virgo_queue"'  -DKBUILD_MODNAME='"virgo_queue"' -c -o /home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o /home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.c

source_/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o := /home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.c

deps_/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o := \
  /home/ksrinivasan/linux-4.13.3/include/linux/virgo_queue.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/socket.h \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/compat.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/socket.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/socket.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/sockios.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/sockios.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sockios.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/uio.h \
    $(wildcard include/config/arch/has/uaccess/flushcache.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/linkage.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/types.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/types.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/types.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/int-ll64.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/int-ll64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/bitsperlong.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/bitsperlong.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/posix_types.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/stddef.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/stddef.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/posix_types.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/stringify.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/alignment/16.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/bitops.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/smp.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/asm.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/rmwcc.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/barrier.h \
    $(wildcard include/config/x86/ppro/fence.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/barrier.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitops/sched.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/arch_hweight.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cpufeatures.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/x86/5level.h) \
    $(wildcard include/config/paravirt.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/x86/intel/memory/protection/keys.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitops/const_hweight.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitops/le.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/byteorder.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/byteorder/little_endian.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/byteorder/little_endian.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/swab.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/swab.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/swab.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/byteorder/generic.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/typecheck.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/init.h \
    $(wildcard include/config/strict/kernel/rwx.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kern_levels.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/kernel.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sysinfo.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
    $(wildcard include/config/x86/internode/cache/shift.h) \
    $(wildcard include/config/x86/vsmp.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/dynamic_debug.h \
    $(wildcard include/config/jump/label.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/jump_label.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/jump_label.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/build_bug.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/bug/on/data/corruption.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/bug.h \
    $(wildcard include/config/debug/bugverbose.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/restart_block.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/current.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/percpu.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/vm86.h) \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/ia32/emulation.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/page.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/physical/align.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/const.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/randomize/memory.h) \
    $(wildcard include/config/randomize/base.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/kaslr.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/x86/mce.h) \
    $(wildcard include/config/x86/vsyscall/emulation.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/range.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/pfn.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/getorder.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/feature/names.h) \
    $(wildcard include/config/x86/fast/feature/tests.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/processor.h \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
    $(wildcard include/config/xen.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/processor-flags.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/processor-flags.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/math_emu.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/ptrace.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/segment.h \
    $(wildcard include/config/x86/32/lazy/gs.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ptrace.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ptrace-abi.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/pgtable/levels.h) \
    $(wildcard include/config/paravirt/debug.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/desc_defs.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/kmap_types.h \
    $(wildcard include/config/debug/highmem.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/kmap_types.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/mem/soft/dirty.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/pgtable_64_types.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/sparsemem.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/pgtable-nop4d.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/spinlock_types.h \
    $(wildcard include/config/paravirt/spinlocks.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/qspinlock_types.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/qrwlock_types.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/ptrace.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/sigcontext.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/msr.h \
    $(wildcard include/config/tracepoints.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/msr-index.h \
    $(wildcard include/config/control.h) \
    $(wildcard include/config/tdp/nominal.h) \
    $(wildcard include/config/tdp/level/1.h) \
    $(wildcard include/config/tdp/level/2.h) \
    $(wildcard include/config/tdp/control.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/errno.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/errno.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/errno-base.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cpumask.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/bitmap.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/string.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/string.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/string_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/msr.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/ioctl.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ioctl.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/ioctl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/ioctl.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/atomic.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cmpxchg.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cmpxchg_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/atomic64_64.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/tracepoint-defs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/atomic-long.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/static_key.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/paravirt.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/frame.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/special_insns.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/fpu/types.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/personality.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/personality.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/div64.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/div64.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/err.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/irqflags.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/uio.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/socket.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ioport.h \
    $(wildcard include/config/memory/hotremove.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sysfs.h \
    $(wildcard include/config/sysfs.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/debug/mutexes.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/spinlock_types.h \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/spinlock.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rwlock_types.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/osq_lock.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/idr.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/radix-tree.h \
    $(wildcard include/config/radix/tree/multiorder.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/preempt.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcupdate.h \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/bottom_half.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcutree.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/spinlock.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/spinlock.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/qspinlock.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/qspinlock.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/qrwlock.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/qrwlock.h \
    $(wildcard include/config/cpu/big/endian.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rwlock.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/cma.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/wait.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/wait.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/seqlock.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/nodemask.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/page-flags-layout.h \
  include/generated/bounds.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/notifier.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/errno.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/errno.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/rwsem.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
    $(wildcard include/config/tree/srcu.h) \
    $(wildcard include/config/srcu.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/wq/watchdog.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/ktime.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/time64.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/time.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/jiffies.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/timex.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/timex.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/param.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/param.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/param.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/timex.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
  include/generated/timeconst.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/timekeeping.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcu_segcblist.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/srcutree.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcu_node_tree.h \
    $(wildcard include/config/rcu/fanout.h) \
    $(wildcard include/config/rcu/fanout/leaf.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/completion.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/mmzone.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/mmzone_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/smp.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/x86/io/apic.h) \
    $(wildcard include/config/debug/nmi/selftest.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/eisa.h) \
    $(wildcard include/config/x86/mpparse.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/mpspec_def.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/x86_init.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/bootparam.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/screen_info.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/screen_info.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/apm_bios.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/apm_bios.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/edd.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/edd.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/ist.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ist.h \
  /home/ksrinivasan/linux-4.13.3/include/video/edid.h \
    $(wildcard include/config/x86.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/video/edid.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/apicdef.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/apic.h \
    $(wildcard include/config/x86/x2apic.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/provide/ohci1394/dma/init.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/x86/intel/mid.h) \
    $(wildcard include/config/intel/txt.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/acpi.h \
    $(wildcard include/config/acpi/apei.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/acpi/numa.h) \
  /home/ksrinivasan/linux-4.13.3/include/acpi/pdc_intel.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/numa.h \
    $(wildcard include/config/numa/emu.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/topology.h \
    $(wildcard include/config/sched/mc/prio.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/topology.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/modify/ldt/syscall.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/realmode.h \
    $(wildcard include/config/acpi/sleep.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/io.h \
    $(wildcard include/config/mtrr.h) \
    $(wildcard include/config/x86/pat.h) \
  arch/x86/include/generated/asm/early_ioremap.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/generic/early/ioremap.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport/map.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/generic/iomap.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /home/ksrinivasan/linux-4.13.3/include/xen/xen.h \
    $(wildcard include/config/xen/dom0.h) \
    $(wildcard include/config/xen/pvh.h) \
  /home/ksrinivasan/linux-4.13.3/include/xen/interface/xen.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/xen/interface.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/xen/interface_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/pvclock-abi.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/xen/hypervisor.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/vsyscall.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/fixmap.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/io_apic.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/irq_vectors.h \
    $(wildcard include/config/have/kvm.h) \
    $(wildcard include/config/pci/msi.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rbtree.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kobject_ns.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/stat.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/stat.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/stat.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/highuid.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kref.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/refcount.h \
    $(wildcard include/config/refcount/full.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/klist.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/ratelimit.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched.h \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/arch/has/scaled/cputime.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/posix/timers.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/ubsan.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/intel/rdt/a.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/kcov.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/vmap/stack.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/security.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sched.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/pid.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rculist.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sem.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sem.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ipc.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/ipc.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ipcbuf.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/ipcbuf.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/sembuf.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/shm.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/shm.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/shmbuf.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/shmbuf.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/shmparam.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kcov.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/kcov.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/time/low/res.h) \
    $(wildcard include/config/timerfd.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/timerqueue.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/seccomp.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/seccomp.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/unistd.h \
    $(wildcard include/config/x86/x32/abi.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/unistd.h \
  arch/x86/include/generated/uapi/asm/unistd_64.h \
  arch/x86/include/generated/asm/unistd_64_x32.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/ia32_unistd.h \
  arch/x86/include/generated/asm/unistd_32_ia32.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/seccomp.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/unistd.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/resource.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/resource.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/resource.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/resource.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/resource.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/latencytop.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/prio.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/signal_types.h \
    $(wildcard include/config/old/sigaction.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/signal.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/signal.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/signal.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/signal-defs.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/siginfo.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/siginfo.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/mm_types_task.h \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/tlbbatch.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/generic/msi/irq/domain.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/generic/msi/irq.h) \
    $(wildcard include/config/dma/cma.h) \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/pinctrl/devinfo.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/pinctrl/consumer.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/seq_file.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/cgroup/writeback.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/fs/encryption.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fs/dax.h) \
    $(wildcard include/config/mandatory/file/locking.h) \
    $(wildcard include/config/migration.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/wait_bit.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kdev_t.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/kdev_t.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dcache.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rculist_bl.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/list_bl.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/bit_spinlock.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/lockref.h \
    $(wildcard include/config/arch/use/cmpxchg/lockref.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/stringhash.h \
    $(wildcard include/config/dcache/word/access.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/hash.h \
    $(wildcard include/config/have/arch/hash.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/path.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/list_lru.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/shrinker.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/mm_types.h \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/have/arch/compat/mmap/bases.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/auxvec.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/auxvec.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/auxvec.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/uprobes.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/uprobes.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/capability.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/capability.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/semaphore.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/fcntl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/fcntl.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/fcntl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/fcntl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/fiemap.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/migrate_mode.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/percpu-rwsem.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcuwait.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rcu_sync.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/delayed_call.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/uuid.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/uuid.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/errseq.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/fs.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/limits.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/percpu_counter.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/dqblk_xfs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dqblk_v1.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dqblk_v2.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dqblk_qtree.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/projid.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/quota.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/nfs_fs_i.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/keys.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/key.h \
    $(wildcard include/config/sysctl.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sysctl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sysctl.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/assoc_array.h \
    $(wildcard include/config/associative/array.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/user.h \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/bpf/syscall.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/pinctrl/pinctrl-state.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/device.h \
    $(wildcard include/config/intel/iommu.h) \
    $(wildcard include/config/amd/iommu.h) \
    $(wildcard include/config/x86/dev/dma/ops.h) \
    $(wildcard include/config/pci/domains.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/pm_wakeup.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kthread.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/module.h \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kmod.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/elf.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/elf.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/user.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/user_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/vdso.h \
    $(wildcard include/config/x86/x32.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/elf.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/elf-em.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/rbtree_latch.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/module.h \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/mcore2.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/melan.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mviac7.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/net.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/random.h \
    $(wildcard include/config/gcc/plugin/latent/entropy.h) \
    $(wildcard include/config/arch/random.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/once.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/random.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/irqnr.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/irqnr.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/archrandom.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kmemcheck.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/net.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/in.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/in.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/libc-compat.h \
    $(wildcard include/config/data.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/inet.h \
  /home/ksrinivasan/linux-4.13.3/include/net/net_namespace.h \
    $(wildcard include/config/nf/conntrack.h) \
    $(wildcard include/config/ipv6.h) \
    $(wildcard include/config/ieee802154/6lowpan.h) \
    $(wildcard include/config/ip/sctp.h) \
    $(wildcard include/config/ip/dccp.h) \
    $(wildcard include/config/netfilter.h) \
    $(wildcard include/config/nf/tables.h) \
    $(wildcard include/config/nf/defrag/ipv6.h) \
    $(wildcard include/config/netfilter/netlink/acct.h) \
    $(wildcard include/config/nf/ct/netlink/timeout.h) \
    $(wildcard include/config/wext/core.h) \
    $(wildcard include/config/xfrm.h) \
    $(wildcard include/config/ip/vs.h) \
    $(wildcard include/config/mpls.h) \
    $(wildcard include/config/can.h) \
    $(wildcard include/config/net/ns.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/flow.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/in6.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/in6.h \
  /home/ksrinivasan/linux-4.13.3/include/net/flow_dissector.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_ether.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/core.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/mib.h \
    $(wildcard include/config/xfrm/statistics.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/snmp.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/snmp.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/u64_stats_sync.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/unix.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/packet.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/ipv4.h \
    $(wildcard include/config/ip/multiple/tables.h) \
    $(wildcard include/config/ip/route/classid.h) \
    $(wildcard include/config/net/l3/master/dev.h) \
    $(wildcard include/config/ip/mroute.h) \
    $(wildcard include/config/ip/mroute/multiple/tables.h) \
    $(wildcard include/config/ip/route/multipath.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_frag.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/ipv6.h \
    $(wildcard include/config/ipv6/multiple/tables.h) \
    $(wildcard include/config/ipv6/mroute.h) \
    $(wildcard include/config/ipv6/mroute/multiple/tables.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/dst_ops.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/ieee802154_6lowpan.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/sctp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/dccp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/netfilter.h \
    $(wildcard include/config/nf/defrag/ipv4.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/netfilter_defs.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netfilter.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/x_tables.h \
    $(wildcard include/config/bridge/nf/ebtables.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/conntrack.h \
    $(wildcard include/config/nf/ct/proto/dccp.h) \
    $(wildcard include/config/nf/ct/proto/sctp.h) \
    $(wildcard include/config/nf/conntrack/events.h) \
    $(wildcard include/config/nf/conntrack/labels.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/list_nulls.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netfilter/nf_conntrack_tcp.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netfilter/nf_conntrack_tcp.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netfilter/nf_conntrack_dccp.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netfilter/nf_conntrack_tuple_common.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netfilter/nf_conntrack_common.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netfilter/nf_conntrack_common.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netfilter/nf_conntrack_sctp.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netfilter/nf_conntrack_sctp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/nftables.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/xfrm.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/xfrm.h \
  /home/ksrinivasan/linux-4.13.3/include/net/flowcache.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/interrupt.h \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
    $(wildcard include/config/irq/timings.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/irqreturn.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/hardirq.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
    $(wildcard include/config/hwlat/tracer.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/vtime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/irq/time/accounting.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/context_tracking_state.h \
    $(wildcard include/config/context/tracking.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/x86/thermal/vector.h) \
    $(wildcard include/config/x86/mce/threshold.h) \
    $(wildcard include/config/x86/mce/amd.h) \
    $(wildcard include/config/hyperv.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/irq.h \
    $(wildcard include/config/generic/irq/effective/aff/mask.h) \
    $(wildcard include/config/generic/irq/ipi.h) \
    $(wildcard include/config/irq/domain/hierarchy.h) \
    $(wildcard include/config/generic/irq/migration.h) \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/hardirqs/sw/resend.h) \
    $(wildcard include/config/generic/irq/legacy/alloc/hwirq.h) \
    $(wildcard include/config/generic/irq/legacy.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/irqhandler.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/io.h \
    $(wildcard include/config/have/arch/huge/vmap.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/slab.h \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/have/hardened/usercopy/allocator.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/vmalloc.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kasan.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/kasan.h \
    $(wildcard include/config/kasan/shadow/offset.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/pgtable.h \
    $(wildcard include/config/debug/wx.h) \
    $(wildcard include/config/have/arch/transparent/hugepage/pud.h) \
    $(wildcard include/config/have/arch/soft/dirty.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/pgtable_64.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/pgtable.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/irq.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/irq_regs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
    $(wildcard include/config/generic/irq/debugfs.h) \
    $(wildcard include/config/sparse/irq.h) \
    $(wildcard include/config/handle/domain/irq.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/hw_irq.h \
    $(wildcard include/config/hpet/timer.h) \
    $(wildcard include/config/dmar/table.h) \
    $(wildcard include/config/ht/irq.h) \
    $(wildcard include/config/x86/uv.h) \
    $(wildcard include/config/vmd.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/profile.h \
    $(wildcard include/config/profiling.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/sections.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/sections.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/extable.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/mpls.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/can.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ns_common.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/skbuff.h \
    $(wildcard include/config/bridge/netfilter.h) \
    $(wildcard include/config/ipv6/ndisc/nodetype.h) \
    $(wildcard include/config/net/switchdev.h) \
    $(wildcard include/config/net/cls/act.h) \
    $(wildcard include/config/net/sched.h) \
    $(wildcard include/config/net/rx/busy/poll.h) \
    $(wildcard include/config/xps.h) \
    $(wildcard include/config/network/secmark.h) \
    $(wildcard include/config/network/phy/timestamping.h) \
    $(wildcard include/config/netfilter/xt/target/trace.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/textsearch.h \
  /home/ksrinivasan/linux-4.13.3/include/net/checksum.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/uaccess.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kasan-checks.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/x86/intel/usercopy.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/smap.h \
    $(wildcard include/config/x86/smap.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/uaccess_64.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/checksum.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/checksum_64.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dma-mapping.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/arch/has/dma/set/coherent/mask.h) \
    $(wildcard include/config/need/dma/map/state.h) \
    $(wildcard include/config/dma/api/debug.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sizes.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dma-debug.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dma-direction.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
    $(wildcard include/config/need/sg/dma/length.h) \
    $(wildcard include/config/arch/has/sg/chain.h) \
    $(wildcard include/config/sg/pool.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/mm.h \
    $(wildcard include/config/have/arch/mmap/rnd/bits.h) \
    $(wildcard include/config/have/arch/mmap/rnd/compat/bits.h) \
    $(wildcard include/config/arch/uses/high/vma/flags.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/metag.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/percpu-refcount.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/page_ext.h \
    $(wildcard include/config/idle/page/tracking.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/stacktrace.h \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/user/stacktrace/support.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/stackdepot.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/page_ref.h \
    $(wildcard include/config/debug/page/ref.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/thp/swap.h) \
    $(wildcard include/config/ksm.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/huge_mm.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/coredump.h \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/debug/tlbflush.h) \
    $(wildcard include/config/debug/vm/vmacache.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/vm_event_item.h \
    $(wildcard include/config/memory/balloon.h) \
    $(wildcard include/config/balloon/compaction.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/dma-mapping.h \
    $(wildcard include/config/isa.h) \
    $(wildcard include/config/x86/dma/remap.h) \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/swiotlb.h \
    $(wildcard include/config/swiotlb.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/swiotlb.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dma-contiguous.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netdev_features.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/clock.h \
    $(wildcard include/config/have/unstable/sched/clock.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/splice.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/pipe_fs_i.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_packet.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/seq_file_net.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/udp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_sock.h \
    $(wildcard include/config/inet.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/jhash.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/unaligned/packed_struct.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netdevice.h \
    $(wildcard include/config/dcb.h) \
    $(wildcard include/config/hyperv/net.h) \
    $(wildcard include/config/wlan.h) \
    $(wildcard include/config/ax25.h) \
    $(wildcard include/config/mac80211/mesh.h) \
    $(wildcard include/config/net/ipip.h) \
    $(wildcard include/config/net/ipgre.h) \
    $(wildcard include/config/ipv6/sit.h) \
    $(wildcard include/config/ipv6/tunnel.h) \
    $(wildcard include/config/rps.h) \
    $(wildcard include/config/netpoll.h) \
    $(wildcard include/config/bql.h) \
    $(wildcard include/config/rfs/accel.h) \
    $(wildcard include/config/fcoe.h) \
    $(wildcard include/config/xfrm/offload.h) \
    $(wildcard include/config/net/poll/controller.h) \
    $(wildcard include/config/libfcoe.h) \
    $(wildcard include/config/wireless/ext.h) \
    $(wildcard include/config/vlan/8021q.h) \
    $(wildcard include/config/net/dsa.h) \
    $(wildcard include/config/tipc.h) \
    $(wildcard include/config/mpls/routing.h) \
    $(wildcard include/config/netfilter/ingress.h) \
    $(wildcard include/config/garp.h) \
    $(wildcard include/config/mrp.h) \
    $(wildcard include/config/cgroup/net/prio.h) \
    $(wildcard include/config/net/flow/limit.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/delay.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/delay.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/delay.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/prefetch.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/dmaengine.h \
    $(wildcard include/config/async/tx/enable/channel/switch.h) \
    $(wildcard include/config/dma/engine.h) \
    $(wildcard include/config/rapidio/dma/engine.h) \
    $(wildcard include/config/async/tx/dma.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/dynamic_queue_limits.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ethtool.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/compat.h \
    $(wildcard include/config/compat/old/sigaction.h) \
    $(wildcard include/config/odd/rt/sigaction.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/hdlc/ioctl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/aio_abi.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/compat.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/user32.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/ethtool.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/if_ether.h \
  /home/ksrinivasan/linux-4.13.3/include/net/dcbnl.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/dcbnl.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netprio_cgroup.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/cgroup.h \
    $(wildcard include/config/sock/cgroup/data.h) \
    $(wildcard include/config/cgroup/net/classid.h) \
    $(wildcard include/config/cgroup/data.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/cgroupstats.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/taskstats.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/nsproxy.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/user_namespace.h \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/persistent/keyrings.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/cgroup-defs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/bpf-cgroup.h \
    $(wildcard include/config/cgroup/bpf.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/bpf.h \
    $(wildcard include/config/efficient/unaligned/access.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/bpf_common.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/cgroup_subsys.h \
    $(wildcard include/config/cgroup/cpuacct.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/cgroup/device.h) \
    $(wildcard include/config/cgroup/freezer.h) \
    $(wildcard include/config/cgroup/perf.h) \
    $(wildcard include/config/cgroup/hugetlb.h) \
    $(wildcard include/config/cgroup/pids.h) \
    $(wildcard include/config/cgroup/rdma.h) \
    $(wildcard include/config/cgroup/debug.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/neighbour.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/netlink.h \
  /home/ksrinivasan/linux-4.13.3/include/net/scm.h \
    $(wildcard include/config/security/network.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/security.h \
    $(wildcard include/config/security/infiniband.h) \
    $(wildcard include/config/security/network/xfrm.h) \
    $(wildcard include/config/security/path.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/securityfs.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netlink.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/netdevice.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/if_link.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_link.h \
    $(wildcard include/config/pending.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_bonding.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/pkt_cls.h \
    $(wildcard include/config/net/cls/ind.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/pkt_sched.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/hashtable.h \
  /home/ksrinivasan/linux-4.13.3/include/net/sock.h \
    $(wildcard include/config/net.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/page_counter.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/memcontrol.h \
    $(wildcard include/config/memcg/swap.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/vmpressure.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/eventfd.h \
    $(wildcard include/config/eventfd.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/writeback.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/flex_proportions.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/backing-dev-defs.h \
    $(wildcard include/config/debug/fs.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/throttling/low.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/bvec.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/bio.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/highmem.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/cacheflush.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/cacheflush.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/mempool.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ioprio.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/iocontext.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/filter.h \
    $(wildcard include/config/arch/has/set/memory.h) \
    $(wildcard include/config/bpf/jit.h) \
    $(wildcard include/config/have/ebpf/jit.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/cryptohash.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/set_memory.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/set_memory.h \
  /home/ksrinivasan/linux-4.13.3/include/asm-generic/set_memory.h \
  /home/ksrinivasan/linux-4.13.3/include/net/sch_generic.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/pkt_cls.h \
  /home/ksrinivasan/linux-4.13.3/include/net/gen_stats.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/gen_stats.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rtnetlink.h \
    $(wildcard include/config/net/ingress.h) \
    $(wildcard include/config/net/egress.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/rtnetlink.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_addr.h \
  /home/ksrinivasan/linux-4.13.3/include/net/rtnetlink.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netlink.h \
    $(wildcard include/config/have/efficient/unaligned/access.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/filter.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/rculist_nulls.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/poll.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/poll.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/poll.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/poll.h \
  /home/ksrinivasan/linux-4.13.3/include/net/dst.h \
  /home/ksrinivasan/linux-4.13.3/include/net/neighbour.h \
  /home/ksrinivasan/linux-4.13.3/include/net/tcp_states.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/net_tstamp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/smc.h \
  /home/ksrinivasan/linux-4.13.3/include/net/request_sock.h \
  /home/ksrinivasan/linux-4.13.3/include/net/netns/hash.h \
  /home/ksrinivasan/linux-4.13.3/include/net/l3mdev.h \
  /home/ksrinivasan/linux-4.13.3/include/net/fib_rules.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/fib_rules.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/udp.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/tcp.h \
    $(wildcard include/config/tcp/md5sig.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/win_minmax.h \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_connection_sock.h \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_timewait_sock.h \
  /home/ksrinivasan/linux-4.13.3/include/net/timewait_sock.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/tcp.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/file.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/freezer.h \
  /home/ksrinivasan/linux-4.13.3/include/net/ip.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ip.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/ip.h \
  /home/ksrinivasan/linux-4.13.3/include/net/route.h \
  /home/ksrinivasan/linux-4.13.3/include/net/inetpeer.h \
  /home/ksrinivasan/linux-4.13.3/include/net/ipv6.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ipv6.h \
    $(wildcard include/config/ipv6/router/pref.h) \
    $(wildcard include/config/ipv6/route/info.h) \
    $(wildcard include/config/ipv6/optimistic/dad.h) \
    $(wildcard include/config/ipv6/seg6/hmac.h) \
    $(wildcard include/config/ipv6/mip6.h) \
    $(wildcard include/config/ipv6/subtrees.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/ipv6.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/icmpv6.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/icmpv6.h \
  /home/ksrinivasan/linux-4.13.3/include/net/if_inet6.h \
  /home/ksrinivasan/linux-4.13.3/include/net/ndisc.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/if_arp.h \
    $(wildcard include/config/firewire/net.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/if_arp.h \
  /home/ksrinivasan/linux-4.13.3/include/net/ip_fib.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/in_route.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/route.h \
  /home/ksrinivasan/linux-4.13.3/include/net/tcp.h \
    $(wildcard include/config/syn/cookies.h) \
    $(wildcard include/config/bpf.h) \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_hashtables.h \
  /home/ksrinivasan/linux-4.13.3/include/net/inet_ecn.h \
  /home/ksrinivasan/linux-4.13.3/include/net/dsfield.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/bpf.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/bpf_types.h \
    $(wildcard include/config/bpf/events.h) \
  /home/ksrinivasan/linux-4.13.3/include/trace/events/skb.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/tracepoint.h \
    $(wildcard include/config/have/syscall/tracepoints.h) \
    $(wildcard include/config/tracepoint.h) \
  /home/ksrinivasan/linux-4.13.3/include/trace/define_trace.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/types.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/signal.h \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/signal.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/jobctl.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sched/task.h \
    $(wildcard include/config/have/copy/thread/tls.h) \
    $(wildcard include/config/have/exit/thread.h) \
    $(wildcard include/config/arch/wants/dynamic/task/struct.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/debug.h \
    $(wildcard include/config/sunrpc/debug.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/sunrpc/debug.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/clnt.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/msg_prot.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/sched.h \
    $(wildcard include/config/sunrpc/swap.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/xdr.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/asm/unaligned.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/unaligned/access_ok.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/unaligned/generic.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/xprt.h \
    $(wildcard include/config/sunrpc/backchannel.h) \
    $(wildcard include/config/sunrpc/backchanel.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/auth.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/utsname.h \
    $(wildcard include/config/uts/ns.h) \
    $(wildcard include/config/proc/sysctl.h) \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/utsname.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/stats.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/proc_fs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/timer.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/rpc_pipe_fs.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/xprtmultipath.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/svcsock.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/svc.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/svcauth.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/cache.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/gss_api.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/sunrpc/svc_xprt.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/kingcobra.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/ctype.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/virgoqueuesvc.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/virgo.h \
  /home/ksrinivasan/linux-4.13.3/arch/x86/include/uapi/asm/ioctls.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/asm-generic/ioctls.h \
  /home/ksrinivasan/linux-4.13.3/include/linux/virgo_config.h \
    $(wildcard include/config/h/.h) \
  /home/ksrinivasan/linux-4.13.3/include/linux/kallsyms.h \
  /home/ksrinivasan/linux-4.13.3/include/net/tls.h \
  /home/ksrinivasan/linux-4.13.3/include/uapi/linux/tls.h \

/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o: $(deps_/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o)

$(deps_/home/ksrinivasan/linux-4.13.3/drivers/virgo/queuing/virgo_queue.o):
