#include "kheap.h"
#include "config.h"
#include "heap.h"
#include "kernel.h"

struct heap kernel_heap;
struct heap_table kernel_heap_table;

void kheap_init() {
    int total_table_entries = VIKASHOS_HEAP_SIZE_BYTES / VIKASHOS_HEAP_BLOCK_SIZE;
    kernel_heap_table.entries = (HEAP_BLOCK_TABLE_ENTRY*)(VIKASHOS_HEAP_TABLE_ADDRESS);
    kernel_heap_table.total = total_table_entries;

    void* end = (void*)(VIKASHOS_HEAP_ADDRESS + VIKASHOS_HEAP_SIZE_BYTES);
    
    int res = heap_create(&kernel_heap, (void*)(VIKASHOS_HEAP_ADDRESS), end, &kernel_heap_table);
    if (res < 0) {
        printf("Failed to create heap");
    }
}
