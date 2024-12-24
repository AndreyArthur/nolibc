#include "../lib/include/exc.h"
#include "../lib/include/heap.h"
#include "../lib/include/int.h"
#include "../lib/include/io.h"
#include "../lib/include/str.h"
#include "../lib/include/sys.h"

void test_heap_alloc(void) {
    char *message = heap_alloc(sizeof(char) * 37);
    str_cpy(message, "I've implemented a heapory allocator!");

    exc_assert(str_cmp(message, "I've implemented a heapory allocator!") == 0);

    heap_free(message);
}

void test_heap_realloc(void) {
    size_t len = 4096;
    uint64_t *arr = heap_realloc(NULL, 0);

    for (size_t i = 0; i < len; i++) {
        arr = heap_realloc(arr, sizeof(uint64_t) * (i + 1));
        arr[i] = i + 1;
    }

    for (size_t i = 0; i < len; i++) {
        exc_assert(arr[i] == i + 1);
    }

    arr = heap_realloc(arr, 0);

    exc_assert(arr == NULL);
}

void _start(void) {
    test_heap_alloc();
    test_heap_realloc();

    sys_exit(0);
}
