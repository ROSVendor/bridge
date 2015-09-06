/**
 * Bridge.IO的默认实现的定义
 */

#ifndef BRIDGE__IO_H
#define BRIDGE__IO_H

#include <stddef.h>
#include <unistd.h>
#include <bridge/error.h>
#include <bridge/macro.h>

#ifdef __cplusplus
extern "C" {
#endif

ret_state _bridge_io_open (int *, const char *, int flag, ...);
ret_state _bridge_io_write(int, const void *, size_t);
ret_state _bridge_io_read (int, void *, size_t);
ret_state _bridge_io_close(int);
ssize_t   _bridge_io_raw_read (int, void *, size_t);
ssize_t   _bridge_io_raw_write(int, const void *, size_t);
int       _bridge_io_raw_open (const char *, int flag, ...);
int       _bridge_io_raw_close(int);

#ifdef __cplusplus
}
#endif

#endif //BRIDGE__IO_H
