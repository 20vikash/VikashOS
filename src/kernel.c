#include "kernel.h"

uint16_t* video_memory = 0;

uint16_t terminal_make_char(char c, char color) {
    return (color << 8) | c; // The first byte is the ascii, 2nd byte is the color. (little endian)
}

void initialize_terminal() {
    video_memory = (uint16_t*)(0xB8000);

    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            video_memory[(y * VGA_WIDTH) + x] = terminal_make_char(' ', 0);
        }
    }
}

void kernel_main() 
{
    initialize_terminal();
    video_memory[0] = terminal_make_char('b', 3);
}
