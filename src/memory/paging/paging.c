#include "paging.h"
#include "memory/heap/kheap.h"

struct paging_4gb_chunk* paging_new_4gb(uint8_t flags) {
    uint32_t* directory = kzalloc();
}
