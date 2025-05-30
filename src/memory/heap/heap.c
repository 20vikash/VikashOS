#include "heap.h"
#include "kernel.h"
#include <stdbool.h>

static bool heap_validate_alignment(void* ptr) {
    return ((unsigned int)ptr % VIKASHOS_HEAP_BLOCK_SIZE) == 0;
}

int heap_create(struct heap* heap, void* ptr, void* end, struct heap_table* table) {
    int res = 0;

    return res;
}
