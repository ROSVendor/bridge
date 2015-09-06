/**
 * Bridge.ModLoader的默认实现的定义
 */

#ifndef BRIDGE__MODLOADER_H
#define BRIDGE__MODLOADER_H

#include <include/error.h>
#include <include/macro.h>

// TODO 实现一个ANSI C的版本
// TODO 添加静态扫描以配置足够的内存空间

extern "C" {
    ret_state _bridge_modloader_require(void **, const char *);
    ret_state _bridge_modloader_replace(void **, const char *, const char *)
    ret_state _bridge_modloader_remove(const void *);
};

#endif //BRIDGE__MODLOADER_H
