/**
 * Bridge.Logger的默认实现
 */

#include <include/bridge.h>

#include <include/module.h>
#include <include/logger.h>
#include <include/_logger.h>

MODULE_NAME("Bridge.Logger");
MODULE_ENTITY(ModLogger, module) = {
    .verbose = _bridge_logger_verbose,
    .info    = _bridge_logger_info,
    .warning = _bridge_logger_warning,
    .error   = _bridge_logger_error,
    .debug   = _bridge_logger_debug
};

