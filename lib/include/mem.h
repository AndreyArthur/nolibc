#ifndef NOLIBC_MEM_H
#define NOLIBC_MEM_H

#include "def.h"

ptrdiff_t mem_cmp(const void *first, const void *second, size_t bytes);

void mem_cpy(void *dest, const void *src, size_t bytes);

#endif
