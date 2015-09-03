/**
 * Bridge.IO的默认实现
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <include/_io.h>
#include <include/_error.h>

//ssize_t (_bridge_io_raw_read) (int, void *, size_t) = read;
//ssize_t (_bridge_io_raw_write)(int, const void *, size_t) = write;
//int     (_bridge_io_raw_open) (const char *, int flag, ...) = open;
//int     (_bridge_io_raw_close)(int) = close;

ret_state _bridge_io_open(int * fd, const char * path, int flag, ...) {
    mode_t mode;
    int file;
    if (flag & O_CREAT) {
        va_list args;
        va_start(args, flag);
        mode = va_arg(args, mode_t);
        va_end(args);
        file = open(path, flag, mode);
    } else {
        file = open(path, flag);
    }
    if (!file) {
        return ES_IO_FIALURE;
    } else {
        *fd = file;
        return ES_NORMAL;
    }
}

ret_state _bridge_io_close(int fd) {
    if (close(fd) == -1) {
        return ES_IO_FIALURE;
    } else {
        return ES_NORMAL;
    }
}

#define CHUNCKED_IO(func, fd, buffer, count) \
    ssize_t chunk_size = 0; \
    ssize_t offset     = 0; \
    do { \
        chunk_size = write(fd, buffer + offset, count - offset); \
        if (!chunk_size) { \
            _bridge_error_set_error(ES_IO_FIALURE, __func__); \
            return ES_IO_FIALURE; \
        } \
        offset += chunk_size; \
    } while (offset < count); \
    return ES_NORMAL

ret_state _bridge_io_read(int fd, void * dest, size_t count) {
    CHUNCKED_IO(read, fd, dest, count);
}

ret_state _bridge_io_write(int fd, const void * data, size_t count) {
    CHUNCKED_IO(write, fd, data, count);
}
#undef CHUNCKED_IO
