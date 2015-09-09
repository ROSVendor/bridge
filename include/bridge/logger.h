/**
 * Bridge.Logger的默认实现的定义
 */

#ifndef BRIDGE_LOGGER_H
#define BRIDGE_LOGGER_H

#include <bridge/module.h>

#ifdef __cplusplus
extern "C" {
#endif

enum LogLevel {
// using stdout
    LOG_VERBOSE,
    LOG_INFO,
// using stderr
    LOG_WARNING,
    LOG_ERROR,
    LOG_DEBUG
};

typedef struct {
    DERIVING_MODULE;
    ret_state (*verbose)(const char *, const char *);
    ret_state (*info)   (const char *, const char *);
    ret_state (*warning)(const char *, const char *);
    ret_state (*error)  (const char *, const char *);
    ret_state (*debug)  (const char *, const char *);
} ModLogger;

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_LOGGER_H
