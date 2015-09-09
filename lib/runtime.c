/**
 * 运行时系统的C封装
 */

#include <stdbool.h>
#include <bridge/runtime.h>
#include <bridge/_runtime.h>
#include <bridge/typesystem.h>

static bool initialized = false;

static TypeSystem type_system = {
};

static inline TypeSystem * get_ts() {
    return &type_system;
}

MODULE_NAME("Bridge.Runtime");
MODULE_ENTITY(BridgeRTS, runtime) = {
    .module_initialize = _bridge_rts_initialize,
    .module_finalize   = _bridge_rts_finalize,
    .get_type_system   = get_ts,
    .get_domain        = _bridge_rts_get_domain,
    .release_domain    = _bridge_rts_release_domain
};
MODULE_ENTITY_GETTER(runtime);

BridgeRTS * _bridge_rts_get_runtime() {
    return &runtime;
}


