/**
 * Bridge运行时系统的定义
 */

#ifndef BRIDGE_RUNTIME_H
#define BRIDGE_RUNTIME_H

#include <bridge/modloader.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void * (query_func)(const char *);

typedef struct {
    query_func (*get_domain)(const char *);
    query_func (*set_domain)(const char *);
    ModLoader  * (*get_module_loader)();
    TypeSystem * (*get_type_system)();
} BridgeRTS;

BridgeRTS * get_runtime();

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_RUNTIME_H
