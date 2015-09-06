/**
 * Bridge的错误处理模块的定义
 */

#ifndef BRIDGE_ERROR_H
#define BRIDGE_ERROR_H

#include <bridge/entity.h>
#include <bridge/error.h>

enum ErrorState {
    ES_NORMAL = 0,
    ES_MOD_LOAD_FIALURE,
    ES_IO_FIALURE,
    ES_FOUNDATION_FIALURE, // 基础设施错误
    ES_COUNT
};

typedef struct {
    DERIVING_NAMED;
    enum ErrorState (*latest_state)();
    const char *    (*latest_info)();
    void            (*set_state)(enum ErrorState);
    void            (*set_info)(const char *);
    void            (*set_error)(enum ErrorState, const char *);
    void            (*reset)();
} ModError;

#endif //BRIDGE_ERROR_H
