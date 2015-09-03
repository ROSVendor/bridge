/**
 * 简单的Bridge.IO模块的默认实现
 */


#ifndef BRIDGE_IO_H
#define BRIDGE_IO_H

#include <stddef.h>
#include <sys/_types/_ssize_t.h>
#include <include/error.h>
#include <include/macro.h>

typedef struct {
    ret_state  (open) (int *, const char *, int flag, ...);
    ret_state  (write)(int, const void *, size_t);
    ret_state  (read) (int, void *, size_t);
    ret_state  (close)(int);
    ssize_t    (raw_read) (int, void *, size_t);
    ssize_t    (raw_write)(int, const void *, size_t);
    int        (raw_open) (const char *, int flag, ...);
    int        (raw_close)(int);
} ModIO;

#endif //BRIDGE_IO_H
