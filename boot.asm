ORG 0
BITS 16

start_:
    jmp short start
    nop

times 33 db 0

; handle_zero:
;     mov ah, 0eh
;     mov bx, 0
;     mov al, 'V'
;     int 0x10
;     iret

start:
    jmp 0x7c0:step2

step2:
    cli
    mov ax, 0x7c0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti

    ; Interrupt starts from the 0x00 of the RAM and its typically the division by 0 error.
    ; Real mode interrupts are set by the BIOS, and protected mode interrupts are different from this.
    ; mov word[ss:0x00], handle_zero ; The size of the interrupt record is 4 bytes.
    ; mov word[ss:0x02], 0x7c0
    ; handle_zero:0x7c0 = offset:segment

    ; int 0

    mov si, message
    call print
    jmp $

print:
    mov bx, 0
.loop:
    lodsb
    cmp al, 0
    je .done
    call print_char
    jmp .loop
.done:
    ret

print_char:
    mov ah, 0eh
    int 0x10
    ret

message: db 'Hello world', 0

times 510 - ($ - $$) db 0
dw 0xAA55
