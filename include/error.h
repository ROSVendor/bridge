/**
 * Bridge的错误处理模块的定义
 */

#ifndef BRIDGE_ERROR_H
#define BRIDGE_ERROR_H

#include <include/entity.h>

enum ErrorState {
    NORMAL,
    MOD_LOAD_FIALURE
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

const ModError * get_mod();
#endif //BRIDGE_ERROR_H
