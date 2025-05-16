#ifndef HEAP_H
#define HEAP_H
#include "config.h"
#include <stdint.h>
#include <stddef.h>

// First 4 bits of the entry (0-3)
#define HEAP_BLOCK_TABLE_ENTRY_TAKEN 0x01
#define HEAP_BLOCK_TABLE_ENTRY_FREE  0x00

// Last 4 bits of the entry (4-7)
#define HEAP_BLOCK_HAS_NEXT 0b10000000
#define HEAP_BLOCK_IS_FREE  0b01000000

typedef unsigned char HEAP_BLOCK_TABLE_ENTRY; // 8 bits (1 entry)

#endif
