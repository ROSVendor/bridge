/**
 * libbridge的对外接口
 */
#include <bridge/bridge.h>
#include <bridge/_error.h>
#include <bridge/_memory.h>
#include <bridge/_runtime.h>
#include <errno.h>

static Bridge self;
static bool   initialized = false;

/**
 * 初始化Bridge系统
 */
ret_state bridge_initialize() {
    if (!initialized) {
        _bridge_rts_initialize();
        _bridge_modloader_initialize();
    }
    return ES_NORMAL;
}

/**
 * 清理Bridge系统
 */
ret_state bridge_finalize() {
    if (initialized) {
        _bridge_memory_free(&self);
        _bridge_modloader_finialize();
        _bridge_rts_finalize();
    }
    return ES_NORMAL;
}

/**
 * 获取Bridge系统入口
 */
ret_state bridge_instance(Bridge * bridge) {
    if (initialized) {
        bridge = &self;
    } else {
        _bridge_error_fatal_here("Bridge not initialized yet");
    }
    return ES_NORMAL;
}
