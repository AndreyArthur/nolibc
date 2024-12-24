#ifndef NOLIBC_IO_H
#define NOLIBC_IO_H

#include "def.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

typedef unsigned int fd_t;

size_t io_fputs(fd_t fd, const char *buf);

#endif
