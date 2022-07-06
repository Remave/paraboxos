; --------- ;

MAGIC     equ 0xe85250d6
ARCH      equ 0
BOOT_SIZE equ (mlt_end - mlt_start)

section .multiboot_header
mlt_start:
	dd MAGIC ; magic mlt
	dd ARCH
	dd BOOT_SIZE
	dd 0x100000000 - (MAGIC + ARCH + BOOT_SIZE)

	dw 0
	dw 0
	dd 8
mlt_end:
;----------------------------;
BITS 32

global start ; start entry
extern kmain ; kernel entry

section .text
start:
	cli
	mov esp, stack_top
	call kmain
sysloop:
	hlt
	jmp sysloop
end:
	jmp $

section .rodata
GTD_start:

GDT_end:

global stack_top

section .bss
stack_bottom:
resb 8192
stack_top:
;============================;