#include "idt.h"
#include "config.h"
#include "memory/memory.h"
#include "kernel.h"
#include "io/io.h"

struct idt_desc idt_descriptors[VIKASHOS_TOTAL_INTERRUPTS];
struct idtr_desc idtr_descriptor;

extern void idt_load(struct idtr_desc *ptr);
extern void int21h();
extern void no_interrupt();

void int21h_handler() {
    printf("You pressed a key bitch\n");
    outb(0x20, 0x20);
}

void no_interrupt_handler() {
    outb(0x20, 0x20); // Ack the PIC
}

void idt_zero() {
    printf("Divide by zero error");
    while(1);
}

void idt_set(int interrupt_no, void *address) {
    struct idt_desc* desc = &idt_descriptors[interrupt_no];
    desc->offset_1 = (uint32_t) address & 0x0000ffff;
    desc->selector = KERNEL_CODE_SELECTOR;
    desc->zero = 0x0;
    desc->type_attr = 0xEE; // 0xE for 32 bit interrupt type, and the first 0xE for setting up privilage and other flags.
    desc->offset_2 = (uint32_t) address >> 16;
}

void idt_init() {
    memset(idt_descriptors, 0, sizeof(idt_descriptors));
    idtr_descriptor.limit = sizeof(idt_descriptors) - 1;
    idtr_descriptor.base = (uint32_t)idt_descriptors;

    for (int i = 0; i < VIKASHOS_TOTAL_INTERRUPTS; i++) {
        idt_set(i, no_interrupt);
    }

    idt_set(0, idt_zero);
    idt_set(0x21, int21h);

    idt_load(&idtr_descriptor);
}
