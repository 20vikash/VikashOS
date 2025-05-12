#include "kernel.h"
#include <stdint.h>

void kernel_main() 
{
    uint16_t* video_memory = (uint16_t*)(0xB8000);

    video_memory[0] = 0x0341; // The first byte is the ascii, 2nd byte is the color. (little endian)
}
