/**
 * Bridge.Error模块的默认实现的定义
 * 用于内部访问和向lib/error.c的导出
 */

#ifndef BRIDGE_ERROR_STATIC_H
#define BRIDGE_ERROR_STATIC_H

void _bridge_error_fatal(const char *reason);
void _bridge_error_fatal_pos(const char * pos, const char *reason);

enum ErrorState _bridge_error_latest_state();
const char *    _bridge_error_latest_info();
void            _bridge_error_set_state(enum ErrorState);
void            _bridge_error_set_info(const char *);
void            _bridge_error_set_error(enum ErrorState, const char *);
void            _bridge_error_reset();

#define _bridge_error_fatal_here(msg) _bridge_error_fatal_pos(__func__, msg)

#endif //BRIDGE_ERROR_STATIC_H
