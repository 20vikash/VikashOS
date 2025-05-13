[BITS 32]
global _start ; Exports this symbol to other files
global problem

extern kernel_main ; Imports the symbol from other files

CODE_SEG equ 0x08
DATA_SEG equ 0x10

_start:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ; Stack grows downwards
    mov ebp, 0x00200000
    mov esp, ebp

    ; Enable the A20 line
    mov al, 0x92 ; Port number for the a20 fast chipset
    or al, 2
    out 0x92, al

    call kernel_main
    jmp $

problem:
    mov eax, 0
    div eax

times 512-($-$$) db 0
