# environment prefix
AARCH64 := /Applications/ArmGNUToolchain/12.3.rel1/aarch64-none-elf/bin/aarch64-none-elf-gcc
QEMU_SYSTEM := /usr/local/bin/qemu-system-aarch64

#compiler flags
CFLAGS :=
CFLAGS += -I.
CFLAGS += -O0
CFLAGS += -ggdb
CFLAGS += -mcpu=cortex-a55
CFLAGS += -march=armv8.2-a+simd+fp16
CFLAGS += -nostartfiles
CFLAGS += -ffreestanding 
CFLAGS += --specs=nosys.specs
CFLAGS += -L. 

#for qemu
QFLAGS:=
QFLAGS += -semihosting
QFLAGS += -m 128M
QFLAGS += -nographic
QFLAGS += -monitor none
QFLAGS += -serial stdio
QFLAGS += -machine virt,gic-version=2,secure=on,virtualization=on
QFLAGS += -cpu cortex-a55
QFLAGS += -kernel

test.elf: startup.s rnda.c 
	$(AARCH64) $(CFLAGS) -Wl,-T,qemu-virt-aarch64.ld -o $@ $^
	$(QEMU_SYSTEM) $(QFLAGS) test.elf