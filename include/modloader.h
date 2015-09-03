/**
 * Bridge的模块加载器的定义部分
 */
#ifndef BRIDGE_MODLDR_H
#define BRIDGE_MODLDR_H

#include <include/module.h>
#include <include/macro.h>

typedef struct {
    ret_state (*require)(void **, const char *);
    ret_state (*remove)(const void *);
} ModLoader;

#endif //BRIDGE_MODLDR_H
