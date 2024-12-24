#ifndef NOLIBC_HEAP_H
#define NOLIBC_HEAP_H

#include "def.h"

void *heap_alloc(size_t size);

void *heap_realloc(void *ptr, size_t size);

void heap_free(void *ptr);

#endif
