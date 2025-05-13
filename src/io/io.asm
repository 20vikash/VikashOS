section .asm

global insb

insb: ; Read one byte from the dx port.
    push ebp
    mov ebp, esp

    xor eax, eax ; Clear out eax (ABI says to have the return value in eax)
    mov edx, [ebp+8]
    in al, dx

    pop ebp
    ret

insw:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, [ebp+8]
    in ax, dx

    pop ebp
    ret
