#include "include/io.h"
#include "include/str.h"
#include "include/sys.h"

size_t io_fputs(fd_t fd, const char *buf) {
    size_t len = str_len(buf);
    return sys_write(fd, buf, len);
}
