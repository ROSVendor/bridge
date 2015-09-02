/**
 * Bridge.Error模块的默认实现的定义
 * 用于内部访问和向lib/error.c的导出
 */

#ifndef BRIDGE_ERROR_STATIC_H
#define BRIDGE_ERROR_STATIC_H

void _bridge_fatal(const char * reason);

enum ErrorState _bridge_error_latest_state();
const char *    _bridge_error_latest_info();
void            _bridge_error_set_state(enum ErrorState);
void            _bridge_error_set_info(const char *);
void            _bridge_error_set_error(enum ErrorState, const char *);
void            _bridge_error_reset();

#endif //BRIDGE_ERROR_STATIC_H
