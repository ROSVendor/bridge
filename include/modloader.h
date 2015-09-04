/**
 * Bridge的模块加载器的定义部分
 */
#ifndef BRIDGE_MODLDR_H
#define BRIDGE_MODLDR_H

#include <include/module.h>
#include <include/macro.h>
#include <include/_modloader.h>

typedef struct {
    ret_state (*require)(void **, const char *);
    ret_state (*remove)(const void *);
} ModLoader;

#define REQUIRE(type, name, mod) \
    type * name; _bridge_modloader_require((void**)&name, mod)

#endif //BRIDGE_MODLDR_H
