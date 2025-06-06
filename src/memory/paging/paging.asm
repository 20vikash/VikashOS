[BITS 32]

section .asm

global paging_load_directory
global enable_paging

paging_load_directory:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]

    mov cr3, eax ; CR3 should contain the address to the page directory.

    pop ebp
    ret

enable_paging:
    push ebp
    mov ebp, esp

    mov eax, cr0
    or eax, 0x80000000 ; Apply the 31st bit to enable paging
    mov cr0, eax

    pop ebp
    ret
