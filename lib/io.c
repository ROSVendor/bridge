/**
 * Bridge.IO的默认实现的封装
 */

#include <include/module.h>
#include <include/_io.h>
#include <include/io.h>

MODULE_NAME("Bridge.IO");
MODULE_ENTITY(ModIO, module) = {
        .open      = _bridge_io_open,
        .read      = _bridge_io_read,
        .write     = _bridge_io_write,
        .close     = _bridge_io_close,
        .raw_open  = _bridge_io_raw_open,
        .raw_read  = _bridge_io_raw_read,
        .raw_write = _bridge_io_write,
        .raw_close = _bridge_io_close
};

ret_state get_entity(void ** addrp) {
        *addrp = &module;
        return ES_NORMAL;
}

