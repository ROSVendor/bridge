/**
 * 定义Bridge中的各种实体结构的通用部分
 */


#ifndef BRIDGE_ENTITY_H
#define BRIDGE_ENTITY_H

#include <bridge/entity.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DERIVING_NAMED const char * name
#define DERIVING_MODULE \
    DERIVING_NAMED; \
    void (*module_initialize)(); \
    void (*module_finalize)()

typedef void (void_func_t)();

typedef struct {
    DERIVING_NAMED;
} _NamedStruct;

typedef struct {
    DERIVING_MODULE;
} _ModuleStruct;

#define GET_MODULE_FIELD(mod, field) (((_ModuleStruct *)(mod))->field)
#define TO_VOID_FN_PTR(val) ((void_func_t *)(val))
#define GET_MODULE_INITIALIZER(mod) (TO_VOID_FN_PTR(GET_MODULE_FIELD(mod, module_initialize)))
#define GET_MODULE_FINALIZER(mod)   (TO_VOID_FN_PTR(GET_MODULE_FIELD(mod, module_finalize)))
#define GET_MODULE_NAME(mod)        ((const char *) GET_MODULE_FIELD(mod, name))
#define GET_AND_CALL(entity, getter) \
    do { \
        void_func_t * fn = getter(entity); \
        if(fn) fn(); \
    } while (0)

#define CALL_MODULE_INITIALIZER(entity) \
    GET_AND_CALL(entity, GET_MODULE_INITIALIZER)

#define CALL_MODULE_FINALIZER(entity) \
    GET_AND_CALL(entity, GET_MODULE_FINALIZER)

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_ENTITY_H
