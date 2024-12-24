#include "../lib/include/bool.h"
#include "../lib/include/exc.h"
#include "../lib/include/sys.h"

void test_bool(void) {
    exc_assert(sizeof(bool) == 1);
    exc_assert(true == 1);
    exc_assert(false == 0);
}

void _start(void) {
    test_bool();

    sys_exit(0);
}
