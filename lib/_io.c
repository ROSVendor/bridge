/**
 * Bridge.IO的默认实现
 */

#include <unistd.h>
#include <include/_io.h>
#include <include/_error.h>

size_t inline _bridge_io_raw_write(int fd, void * data, size_t count) {
    return write(fd, data, count);
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

