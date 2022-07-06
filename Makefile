# i386elfgcc := /usr/local/i386elfgcc/bin/
BIN        := ./bin
BIN_KERNEL := ./bin/kernel
BIN_SHELL  := ./bin/shell
ISO        := ./iso

os: kernel ld grub

kernel:
	nasm -f elf32 boot.asm -o $(BIN)/boot.o
	gcc -m32 -c ./kernel/kernel.c -o $(BIN_KERNEL)/kernel.o
	gcc -m32 -c ./shell/shell.c -o $(BIN_SHELL)/shell.o

ld:
	ld -m elf_i386 -T kernel.ld -o kernel.bin $(BIN)/boot.o $(BIN_KERNEL)/kernel.o $(BIN_SHELL)/shell.o

grub:
	cp kernel.bin $(ISO)/boot/kernel.bin
	grub-mkrescue -o paraboxos.iso $(ISO)

clean:
	rm *.bin

qemu:
	qemu-system-x86_64 -cdrom paraboxos.iso