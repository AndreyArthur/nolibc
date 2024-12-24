#include "../lib/include/exc.h"
#include "../lib/include/int.h"
#include "../lib/include/sys.h"

void test_ints(void) {
    exc_assert(sizeof(int8_t) == 1);
    exc_assert(sizeof(uint8_t) == 1);
    exc_assert(sizeof(int16_t) == 2);
    exc_assert(sizeof(uint16_t) == 2);
    exc_assert(sizeof(int32_t) == 4);
    exc_assert(sizeof(uint32_t) == 4);
    exc_assert(sizeof(int64_t) == 8);
    exc_assert(sizeof(uint64_t) == 8);
}

void _start(void) {
    test_ints();

    sys_exit(0);
}
