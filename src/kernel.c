#include "kernel.h"
#include <stdint.h>
#include <stddef.h>
#include "idt/idt.h"
#include "io/io.h"
#include "memory/heap/kheap.h"

uint16_t* video_memory = 0;
uint16_t terminal_row = 0;
uint16_t terminal_column = 0;

uint16_t terminal_make_char(char c, char color) {
    return (color << 8) | c; // The first byte is the ascii, 2nd byte is the color. (little endian)
}

size_t strlen(const char *str) {
    size_t len = 0;

    while(str[len]) {
        len++;
    }

    return len;
}

void terminal_put_char(int x, int y, char c, char color) {
    video_memory[(y * VGA_WIDTH) + x] = terminal_make_char(c, color);
}

void terminal_write_char(char c, char color) {
    if (c == '\n') {
        terminal_column = 0;
        terminal_row++;
        return;
    }

    terminal_put_char(terminal_column, terminal_row, c, color);

    terminal_column++;
    if (terminal_column % VGA_WIDTH == 0) {
        terminal_column = 0;
        terminal_row++;
    }
}

void printf(char *c) {
    size_t len = strlen(c);

    for (int i = 0; i < len; i++)
    {
        terminal_write_char(c[i], 15);
    }
}

void initialize_terminal() {
    video_memory = (uint16_t*)(0xB8000);
    terminal_row = 0;
    terminal_column = 0;

    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            terminal_put_char(x, y, ' ', 0);
        }
    }
}

void kernel_main() 
{
    initialize_terminal();
    kheap_init();
    idt_init();

    void* ptr1 = kmalloc(50);
    // void* ptr2 = kmalloc(5000);

    printf(ptr1);
    printf("Hello world");
}
