/**
 * Bridge的内建简单的错误控制
 * 仅仅是对默认实现的一层封装
 */

#include <include/module.h>
#include <include/error.h>
#include <include/_error.h>

static const ModError module = {
    .name         = "Bridge.Error",
    .latest_state = _bridge_error_latest_state,
    .latest_info  = _bridge_error_latest_info,
    .set_error    = _bridge_error_set_error,
    .set_state    = _bridge_error_set_state,
    .set_info     = _bridge_error_set_info,
    .reset        = _bridge_error_reset
};

MODULE_ENTITY(ModError, module);

