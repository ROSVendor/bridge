/**
 * Bridge.Error模块的默认实现
 * 用于内部访问和向lib/error.c的导出
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/bridge.h>
#include <include/config.h>
#include <include/_error.h>

char            info[MAX_ERROR_INFO_LEN]  = {};
enum ErrorState state                     = NORMAL;



void inline _bridge_error_fatal_pos(const char * pos, const char *reason) {
    char * ret;
    asprintf(&ret, "[%s] %s", pos, reason);
    _bridge_error_fatal(ret);
}

void _bridge_error_fatal(const char *reason) {
    if (reason) {
        fprintf(stderr, "[FATAL]");
        perror(reason);
    } else {
        perror("Unspecified fatal error");
    }
    exit(EXIT_FAILURE);
}

enum ErrorState _bridge_error_latest_state() {
    return state;
}

const char * _bridge_error_latest_info() {
    return info;
}

void _bridge_error_reset() {
    info[0] = '\0';
    state   = NORMAL;
}

void _bridge_error_set_state(enum ErrorState s) {
    state = s;
}

void _bridge_error_set_info(const char * i) {
    strncpy(info, i, MAX_ERROR_INFO_LEN);
}

void _bridge_error_set_error(enum ErrorState s, const char * i) {
    _bridge_error_set_state(s);
    _bridge_error_set_info(i);
}
