#include "include/exc.h"
#include "include/io.h"
#include "include/sys.h"

void exc_assert_impl(const char *exp) {
    io_fputs(STDERR_FILENO, "assertion \"");
    io_fputs(STDERR_FILENO, exp);
    io_fputs(STDERR_FILENO, "\" failed\n");
    sys_exit(1);
}

void exc_unreachable_impl(void) {
    io_fputs(STDERR_FILENO, "unreachable code reached\n");
    sys_exit(1);
}

void exc_panic_impl(const char *message) {
    io_fputs(STDERR_FILENO, "PANIC! \"");
    io_fputs(STDERR_FILENO, message);
    io_fputs(STDERR_FILENO, "\"\n");
    sys_exit(1);
}
