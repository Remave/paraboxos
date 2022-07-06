# export PATH=$PATH:/usr/local/i386elfgcc/bin

nasm -f elf32 boot.asm -o ./bin/boot.o
gcc -m32 -c ./kernel/kernel.c -o ./bin/kernel/kernel.o
gcc -m32 -c ./shell/shell.c -o ./bin/shell/shell.o

ld -m elf_i386 -T kernel.ld -o kernel.bin ./bin/boot.o ./bin/kernel/kernel.o ./bin/shell/shell.o

cp kernel.bin ./iso/boot/kernel.bin
grub-mkrescue -o paraboxos.iso ./iso
