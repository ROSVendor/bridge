/**
 * Bridge的内建简单的错误控制
 * 仅仅是对默认实现的一层封装
 */

#include <bridge/module.h>
#include <bridge/error.h>
#include <bridge/_error.h>

MODULE_NAME("Bridge.Error");
MODULE_ENTITY(ModError, module) = {
    .latest_state = _bridge_error_latest_state,
    .latest_info  = _bridge_error_latest_info,
    .set_error    = _bridge_error_set_error,
    .set_state    = _bridge_error_set_state,
    .set_info     = _bridge_error_set_info,
    .reset        = _bridge_error_reset
};
MODULE_ENTITY_GETTER(module);

