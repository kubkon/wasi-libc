#ifndef __wasi_libc_h
#define __wasi_libc_h

#include <__typedef_off_t.h>
#include <__struct_timespec.h>

#ifdef __cplusplus
extern "C" {
#endif

struct stat;
struct timespec;

void __wasilibc_init_preopen(void);
int __wasilibc_register_preopened_fd(int fd, const char *path)
    __attribute__((__warn_unused_result__));
int __wasilibc_fd_renumber(int fd, int newfd)
    __attribute__((__warn_unused_result__));
int __wasilibc_unlinkat(int fd, const char *path)
    __attribute__((__warn_unused_result__));
int __wasilibc_rmdirat(int fd, const char *path)
    __attribute__((__warn_unused_result__));
off_t __wasilibc_tell(int fd)
    __attribute__((__warn_unused_result__));

/* Non-`at` forms of various `*at` functions. */
int __wasilibc_access(const char *pathname, int mode, int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_stat(const char *__restrict pathname, struct stat *__restrict statbuf, int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_utimens(const char *pathname, const struct timespec times[2], int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_link(const char *oldpath, const char *newpath, int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_link_oldat(int olddirfd, const char *oldpath, const char *newpath, int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_link_newat(const char *oldpath, int newdirfd, const char *newpath, int flags)
    __attribute__((__warn_unused_result__));
int __wasilibc_rename_oldat(int olddirfd, const char *oldpath, const char *newpath)
    __attribute__((__warn_unused_result__));
int __wasilibc_rename_newat(const char *oldpath, int newdirfd, const char *newpath)
    __attribute__((__warn_unused_result__));

#ifdef __cplusplus
}
#endif

#endif
