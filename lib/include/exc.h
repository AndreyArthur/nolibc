#ifndef NOLIBC_EXC_H
#define NOLIBC_EXC_H

void exc_assert_impl(const char *exp);

void exc_unreachable_impl(void);

void exc_panic_impl(const char *message);

#define exc_assert(exp)                                                        \
    {                                                                          \
        if (!(exp)) {                                                          \
            exc_assert_impl(#exp);                                             \
        }                                                                      \
    }

#define exc_unreachable() exc_unreachable_impl()

#define exc_panic(message) exc_panic_impl(message)

#endif
