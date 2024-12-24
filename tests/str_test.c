#include "../lib/include/exc.h"
#include "../lib/include/io.h"
#include "../lib/include/str.h"
#include "../lib/include/sys.h"

void test_str_len(void) {
    char *message = "Hello, World!";
    size_t len = str_len(message);

    exc_assert(len == 13);
}

void test_str_cpy(void) {
    char buf[32];
    str_cpy(buf, "Hello, World!");

    exc_assert(str_len(buf) == 13);
    exc_assert(str_cmp(buf, "Hello, World!") == 0);
}

void test_str_cmp(void) {
    char first[32], second[32];
    str_cpy(first, "Hello, World!");
    str_cpy(second, "Hello, World!");

    exc_assert(str_cmp(first, second) == 0);

    str_cpy(first, "Hello, World!");
    str_cpy(second, "Hello, World");

    exc_assert(str_cmp(first, second) == 1);

    str_cpy(first, "Hello, World");
    str_cpy(second, "Hello, World!");

    exc_assert(str_cmp(first, second) == -1);

    str_cpy(first, "Hello, Worle!");
    str_cpy(second, "Hello, World!");

    exc_assert(str_cmp(first, second) == 1);

    str_cpy(first, "Hello, World");
    str_cpy(second, "Hello, Worle!");

    exc_assert(str_cmp(first, second) == -1);
}

void _start(void) {
    test_str_len();
    test_str_cpy();
    test_str_cmp();

    sys_exit(0);
}
