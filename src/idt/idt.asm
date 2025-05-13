section .asm

global idt_load

idt_load:
    push ebp
    mov ebp, esp

    mov ebx, [epb+8]
    lidt [ebx]

    pop ebp
    ret
