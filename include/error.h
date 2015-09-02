/**
 * Bridge的错误报告
 */

#ifndef BRIDGE_ERROR_H
#define BRIDGE_ERROR_H

enum ErrorState {
    NORMAL,
};

typedef struct {
    enum ErrorState (*latest_state)();
    const char *    (*latest_info)();
    void            (*set_state)(enum ErrorState);
    void            (*set_info)(enum const char *);
    void            (*reset)();
} ModError;

const ModuleErr * get_mod();
#endif //BRIDGE_ERROR_H
