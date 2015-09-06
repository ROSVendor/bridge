/**
 * 简单的Bridge.IO模块的默认实现
 */


#ifndef BRIDGE_IO_H
#define BRIDGE_IO_H

#include <stddef.h>
#include <unistd.h>
#include <bridge/error.h>
#include <bridge/macro.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ret_state  (*open) (int *, const char *, int flag, ...);
    ret_state  (*write)(int, const void *, size_t);
    ret_state  (*read) (int, void *, size_t);
    ret_state  (*close)(int);
    ssize_t    (*raw_read) (int, void *, size_t);
    ssize_t    (*raw_write)(int, const void *, size_t);
    int        (*raw_open) (const char *, int flag, ...);
    int        (*raw_close)(int);
} ModIO;

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_IO_H
