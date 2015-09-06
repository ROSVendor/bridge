/**
 * Bridge.Logger的默认实现的定义
 */
#ifndef BRIDGE__LOGGER_H
#define BRIDGE__LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

ret_state _bridge_logger_verbose(const char *, const char *);
ret_state _bridge_logger_info   (const char *, const char *);
ret_state _bridge_logger_warning(const char *, const char *);
ret_state _bridge_logger_error  (const char *, const char *);
ret_state _bridge_logger_debug  (const char *, const char *);

#ifdef __cplusplus
}
#endif

#endif //BRIDGE__LOGGER_H
