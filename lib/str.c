#include "include/str.h"

size_t str_len(const char *buf) {
    size_t len = 0;
    while (buf[len] != '\0' && len != SIZE_MAX) {
        len++;
    }
    return len;
}

void str_cpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

ptrdiff_t str_cmp(const char *first, const char *second) {
    size_t i = 0, j = 0;

    while (first[i] != '\0') {
        if (second[j] == '\0') {
            return 1;
        }
        if (second[j] > first[i]) {
            return -1;
        }
        if (first[i] > second[j]) {
            return 1;
        }

        i++;
        j++;
    }

    if (second[j] != '\0') {
        return -1;
    }

    return 0;
}
