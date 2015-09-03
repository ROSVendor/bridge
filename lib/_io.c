/**
 * Bridge.IO的默认实现
 */

#include <unistd.h>
#include <sys/stat.h>
#include <varargs.h>
#include <fcntl.h>
#include <include/_io.h>
#include <include/_error.h>

size_t    (*raw_read) (int, void *, size_t) = read;
size_t    (*raw_write)(int, void *, size_t) = write;
int       (*raw_open) (const char *, int flag, ...) = open;
int       (*raw_close)(int) = close;

ret_state __bridge_io_open(int * fd, const char * path, int flag, ...) {
    mode_t mode;
    int file;
    if (flag & O_CREAT) {
        va_list args;
        va_start(args, flag);
        mode = va_arg(args, mode_t);
        va_end(args);
        file = raw_open(path, flag, mode);
    } else {
        file = raw_open(path, flag);
    }
    if (!file) {
        return ES_IO_FIALURE;
    } else {
        *fd = file;
        return ES_NORMAL;
    }
}

ret_state _bridge_io_close(int fd) {
    if (raw_close(fd) == -1) {
        return ES_IO_FIALURE;
    } else {
        return ES_NORMAL;
    }
}

ret_state _bridge_io_read(int fd, void * dest, size_t count) {
    size_t chunk_size = 0;
    size_t offset     = 0;
    do {
        chunk_size = _bridge_io_raw_read(fd, dest + offset, count - offset);
        if (!chunk_size) {
            _bridge_error_set_error(ES_IO_FIALURE, __func__);
            return ES_IO_FIALURE;
        }
    } while (offset < count) ;
    return ES_NORMAL;
}

ret_state _bridge_io_write(int fd, void * data, size_t count) {
    size_t chunk_size = 0;
    size_t offset     = 0;
    do {
        chunk_size = _bridge_io_raw_write(fd, data + offset, count - offset);
        if (!chunk_size) {
            _bridge_error_set_error(ES_IO_FIALURE, __func__);
            return ES_IO_FIALURE;
        }
    } while (offset < count) ;
    return ES_NORMAL;
}

