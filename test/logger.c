/**
 * Bridge.Logger的测试程序
 */

#include <bridge/module.h>
#include <bridge/_logger.h>


int main() {
    _bridge_logger_verbose("V", "LINENO");
    _bridge_logger_info("I",    "LINENO");
    _bridge_logger_warning("W", "LINENO");
    _bridge_logger_debug("D",   "LINENO");
    _bridge_logger_error("E",   "LINENO");
    return 0;
}
