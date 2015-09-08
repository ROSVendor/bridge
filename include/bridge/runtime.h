/**
 * Bridge运行时系统的定义
 */

#ifndef BRIDGE_RUNTIME_H
#define BRIDGE_RUNTIME_H

#include <bridge/modloader.h>
#include <bridge/typesystem.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void * (query_func)(void *, const char *);
typedef void * (set_func)  (void *, const char *, void *);

typedef struct {
    void       * (*get_domain)(const char *);
    ModLoader  * (*get_module_loader)();
    TypeSystem * (*get_type_system)();
} BridgeRTS;

BridgeRTS * get_runtime();

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_RUNTIME_H
