#ifndef NOLIBC_SYS_H
#define NOLIBC_SYS_H

#include "def.h"
#include "int.h"

#define MMAP_PROT_READ 0x1
#define MMAP_PROT_WRITE 0x2
#define MMAP_PROT_EXEC 0x4

#define MMAP_MAP_SHARED 0x01
#define MMAP_MAP_PRIVATE 0x02
#define MMAP_MAP_ANONYMOUS 0x20

void sys_exit(int error_code);

size_t sys_write(unsigned int fd, const char *buf, size_t count);

void sys_read(unsigned int fd, char *buf, size_t count);

void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd,
               int64_t offset);

void sys_munmap(void *addr, size_t len);

#endif
