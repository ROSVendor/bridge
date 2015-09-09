/**
 * Bridge的模块加载器的定义部分
 */
#ifndef BRIDGE_MODLDR_H
#define BRIDGE_MODLDR_H

#include <bridge/module.h>
#include <bridge/macro.h>
#include <bridge/_modloader.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DERIVING_MODULE;
    ret_state (*require)(void **, const char *);
    ret_state (*replace)(void **, const char *, const char *);
    ret_state (*remove)(const void *);
} ModLoader;

#define REQUIRE_AS(type, name, mod) \
    _bridge_modloader_require((void**)&name, mod)

#define REQUIRE(type, name, mod) \
    type * name; REQUIRE_AS(type, name, mod)

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_MODLDR_H
