#include "include/sys.h"
#include "include/int.h"
#include "include/io.h"

#define SYS_EXIT 60
#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_MMAP 9
#define SYS_MUNMAP 11

size_t mmap_mapped_memory = 0;

void sys_exit(int error_code) {
#ifdef NOSTDLIB_MMAP_TRACKER
    if (mmap_mapped_memory != 0) {
        io_fputs(STDERR_FILENO, "Mmap not unmapped all of it's memory!\n");
    }
#endif
    asm("syscall" : : "a"(SYS_EXIT), "D"(error_code));
}

void sys_read(unsigned int fd, char *buf, size_t count) {
    asm("syscall" ::"a"(SYS_READ), "D"(fd), "S"(buf), "d"(count));
}

size_t sys_write(unsigned int fd, const char *buf, size_t count) {
    asm("syscall" ::"a"(SYS_WRITE), "D"(fd), "S"(buf), "d"(count));
    return 0;
}

void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd,
               int64_t offset) {
    void *result;
    asm volatile("mov $9, %%rax\n"
                 "mov %1, %%rdi\n"
                 "mov %2, %%rsi\n"
                 "mov %3, %%rdx\n"
                 "mov %4, %%r10\n"
                 "mov %5, %%r8\n"
                 "mov %6, %%r9\n"
                 "syscall\n"
                 "mov %%rax, %0\n"
                 : "=r"(result)
                 : "r"((long)addr), "r"((long)length), "r"((long)prot),
                   "r"((long)flags), "r"((long)fd), "r"((long)offset)
                 : "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9", "memory");
    mmap_mapped_memory += length;
    return result;
}

void sys_munmap(void *addr, size_t len) {
    mmap_mapped_memory -= len;
    asm("syscall" ::"a"(SYS_MUNMAP), "D"(addr), "S"(len));
}
