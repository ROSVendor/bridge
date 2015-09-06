/**
 * Bridge的模块加载器的默认实现
 * 这个模块在Bridge启动时自动加载
 * 但是依然可以替换
 * TODO: 提供可配置的Bridge Module Loader
 */

#include <bridge/_modloader.h>
#include <bridge/modloader.h>

MODULE_NAME("Bridge.ModLoader");
MODULE_ENTITY(ModLoader, module) = {
    .require = _bridge_modloader_require,
    .remove  = _bridge_modloader_remove
};
MODULE_ENTITY_GETTER(module);
