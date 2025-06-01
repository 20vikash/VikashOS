[BITS 32]

section .asm

global paging_load_directory

paging_load_directory:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]

    mov cr3, eax ; CR3 should contain the address to the page directory.

    pop ebp
    ret
