#include "../lib/include/def.h"
#include "../lib/include/exc.h"
#include "../lib/include/io.h"
#include "../lib/include/sys.h"

void test_size_t(void) {
    exc_assert(sizeof(size_t) == 8);

    size_t size = 0;
    exc_assert(--size == ~(size_t)0);
}

void test_ptrdiff_t(void) {
    exc_assert(sizeof(ptrdiff_t) == 8);

    ptrdiff_t ptrdiff = 0;
    exc_assert(--ptrdiff == (ptrdiff_t)-1);
}

void test_null(void) { exc_assert(NULL == 0); }

void test_size_max(void) { exc_assert(SIZE_MAX + 1 == 0); }

void _start(void) {
    test_size_t();
    test_ptrdiff_t();
    test_null();
    test_size_max();

    sys_exit(0);
}
