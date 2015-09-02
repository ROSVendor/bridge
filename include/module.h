/**
 * Bridge的模块类别标识和辅助工具
 */

#ifndef BRIDGE_MODULE_H
#define BRIDGE_MODULE_H

enum InnerModuleType {
    MOD_ERROR = 0,
    MOD_MEMORY,
    MOD_LOGGER,
    INNER_MOD_COUNT
};

#define FUNC_GET_MOD_ENTITY get_module_entity

#define MODULE_ENTITY(type, mod)       \
    const type * FUNC_GET_MOD_ENTITY() { \
        return &mod;                   \
    }

#endif //BRIDGE_MODULE_H
