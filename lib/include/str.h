#ifndef NOLIBC_STR_H
#define NOLIBC_STR_H

#include "def.h"

size_t str_len(const char *buf);

void str_cpy(char *dest, const char *src);

ptrdiff_t str_cmp(const char *first, const char *second);

#endif
