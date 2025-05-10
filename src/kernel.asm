[BITS 32]
load32:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp

    ; Enable the A20 line
    mov al, 0x92 ; Port number for the a20 fast chipset
    or al, 2
    out 0x92, al

    jmp $
