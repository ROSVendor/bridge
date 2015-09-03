/**
 * Bridge.IO的默认实现的封装
 */

#include <fcntl.h>
#include <unistd.h>
#include <include/module.h>
#include <include/_io.h>
#include <include/io.h>

MODULE_NAME("Bridge.IO");
MODULE_ENTITY(ModIO, module) = {
    .open      = _bridge_io_open,
    .read      = _bridge_io_read,
    .write     = _bridge_io_write,
    .close     = _bridge_io_close,
    .raw_open  = open,
    .raw_read  = read,
    .raw_write = write,
    .raw_close = close
};

ret_state get_entity(void ** addrp) {
        *addrp = &module;
        return ES_NORMAL;
}

