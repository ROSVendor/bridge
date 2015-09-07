/**
 * 运行时系统的C封装
 */

#include <stdbool.h>
#include <bridge/runtime.h>

static bool initialized = false;
static BridgeRTS runtime {

};

static BridgeRTS * get_runtime() {
    return &runtime;
}
