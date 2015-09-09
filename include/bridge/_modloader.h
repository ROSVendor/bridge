/**
 * Bridge.ModLoader的默认实现的定义
 */

#ifndef BRIDGE__MODLOADER_H
#define BRIDGE__MODLOADER_H

#include <bridge/error.h>
#include <bridge/macro.h>

// TODO 实现一个ANSI C的版本
// TODO 添加静态扫描以配置足够的内存空间

#ifdef __cplusplus
extern "C" {
#endif
    ret_state _bridge_modloader_require(void **, const char *);
    ret_state _bridge_modloader_replace(void **, const char *, const char *);
    ret_state _bridge_modloader_remove(const void *);
    void      _bridge_modloader_initialize();
    void      _bridge_modloader_finialize();
#ifdef __cplusplus
};
#endif

#endif //BRIDGE__MODLOADER_H
