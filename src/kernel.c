#include "kernel.h"

void kernel_main() 
{
    char* video_memory = (char*)(0xB8000);

    video_memory[0] = 'A';
    video_memory[1] = 2;
}
