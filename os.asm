mov ah, 0x0e ;scroling teletype BIOS routine

mov al, 'A'
int 0x10

jmp $

times 510-($-$$) db 0
dw 0xaa55
