/**
 * Bridge.Logger的默认实现
 */

#include <stdio.h>
#include <unistd.h>
#include <include/bridge.h>
#include <include/_logger.h>
#include <include/_io.h>
#include <include/_error.h>

static int fd_out = STDOUT_FILENO;
static int fd_err = STDERR_FILENO;

static ret_state write_log(fd, level, catalog, message)
    int fd;
    const char * level;
    const char * catalog;
    const char * message;
{
    size_t length;
    int ret;
    char * reason;
    // TODO 处理潜在的Foundation Failure
    ret = asprintf(&reason, "[%s][%s]: %s\n", level, catalog, message);
    if (ret > 0) {
        length = (size_t) ret;
        return _bridge_io_write(fd, reason, length);
    } else {
        _bridge_error_set_state(ES_IO_FIALURE);
    }
    return ES_NORMAL;
}

ret_state _bridge_logger_verbose(const char * l, const char * m) {
    return write_log(fd_out, "VERBOSE", l, m);
}
ret_state _bridge_logger_info   (const char * l, const char * m) {
    return write_log(fd_out, "INFO", l, m);
}
ret_state _bridge_logger_warning(const char * l, const char * m) {
    return write_log(fd_err, "WARNING", l, m);
}
ret_state _bridge_logger_error  (const char * l, const char * m) {
    return write_log(fd_err, "ERROR", l, m);
}
ret_state _bridge_logger_debug  (const char * l, const char * m) {
    return write_log(fd_err, "DEBUG", l, m);
}
