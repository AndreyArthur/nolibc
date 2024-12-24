#include "../lib/include/exc.h"
#include "../lib/include/int.h"
#include "../lib/include/io.h"
#include "../lib/include/mem.h"
#include "../lib/include/str.h"
#include "../lib/include/sys.h"

void test_mem_cmp(void) {
    {
        uint8_t first[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        uint8_t second[8] = {1, 2, 3, 4, 5, 6, 7, 8};

        exc_assert(mem_cmp(first, second, sizeof(uint8_t) * 8) == 0);
    }

    {
        uint8_t first[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        uint8_t second[8] = {1, 2, 3, 4, 5, 6, 7, 7};

        exc_assert(mem_cmp(first, second, sizeof(uint8_t) * 8) == 1);
    }

    {
        uint8_t first[8] = {1, 2, 3, 4, 5, 6, 7, 7};
        uint8_t second[8] = {1, 2, 3, 4, 5, 6, 7, 8};

        exc_assert(mem_cmp(first, second, sizeof(uint8_t) * 8) == -1);
    }
}

void test_mem_cpy(void) {
    uint8_t src[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t dest[8];
    mem_cpy(dest, src, sizeof(uint8_t) * 8);

    exc_assert(mem_cmp(dest, src, sizeof(uint8_t) * 8) == 0);
}

void _start(void) {
    test_mem_cmp();
    test_mem_cpy();

    sys_exit(0);
}
