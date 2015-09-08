/**
 * 运行时系统的C封装
 */

#include <stdbool.h>
#include <bridge/runtime.h>
#include <bridge/typesystem.h>

static bool initialized = false;

static TypeSystem type_system = {
};

static inline TypeSystem * get_ts() {
    return &type_system;
}

static BridgeRTS runtime = {
    .get_type_system = get_ts
};

BridgeRTS * get_runtime() {
    return &runtime;
}

