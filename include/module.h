/**
 * Bridge的模块类别标识和辅助工具
 */

#ifndef BRIDGE_MODULE_H
#define BRIDGE_MODULE_H

#include <include/entity.h>
#include <include/error.h>
#include <include/macro.h>

#ifdef __cplusplus
extern "C" {
#endif

enum InnerModuleType {
    MOD_ERROR = 0,
    MOD_MEMORY,
    MOD_LOGGER,
    INNER_MOD_COUNT
};

/**
 * Bridge.ModLoader用于获取模块的主要接口
 */
ret_state get_entity(void **);

/**
 * entity和名称被独立链接到一个自定义的段里
 * 这意味着Entity的name字段【不需要】被定义
 * 反正定义了也会被覆盖...
 * TODO 布局模块的结构
 */
#define SEPSEC(x)  __attribute__((section(x)))
#define MODULE_NAME(literal) \
    const char * module_name SEPSEC("bridge,module") = literal

#define MODULE_ENTITY(type, entity) \
    type SEPSEC("bridge,module") entity

#define MODULE_ENTITY_GETTER(entity) \
    ret_state get_entity(void ** addrp) { \
        *addrp = &entity;                 \
        return ES_NORMAL;                 \
    };                                    \
    const size_t module_entity_size SEPSEC("bridge,entitysize") = sizeof(entity)

#define MODULE_CONSTRUCTOR \
    void module_constructor##__LINE__() __attribute__((constructor))

#define MODULE_FINALIZER \
    void module_finalizer##__LINE__() __attribute__((destructor))

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_MODULE_H
