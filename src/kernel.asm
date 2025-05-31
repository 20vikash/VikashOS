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

    mov al, 00010001b
    out 0x20, al ; Tell master PIC to initialize

    mov al, 0x20 ; Interrupt 0x20 is where the master PIC's ISR should start
    out 0x21, al

    mov al, 00000001b ; Operate in x86 mode
    out 0x21, al

    ; End remap of master PIC

    call kernel_main
    jmp $

times 512-($-$$) db 0
