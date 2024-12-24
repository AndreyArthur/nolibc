#include "include/def.h"
#include "include/int.h"

ptrdiff_t mem_cmp(const void *first, const void *second, size_t bytes) {
    for (size_t i = 0; i < bytes; i++) {
        if (((uint8_t *)first)[i] > ((uint8_t *)second)[i]) {
            return 1;
        }

        if (((uint8_t *)first)[i] < ((uint8_t *)second)[i]) {
            return -1;
        }
    }

    return 0;
}

void mem_cpy(void *dest, const void *src, size_t bytes) {
    uint8_t *dest_as_bytes = dest;
    const uint8_t *src_as_bytes = src;

    for (size_t i = 0; i < bytes; i++) {
        dest_as_bytes[i] = src_as_bytes[i];
    }
}
