/**
 * 对Bridge.Memory的默认实现的封装
 */


#include <bridge/module.h>
#include <bridge/memory.h>
#include <bridge/_memory.h>

MODULE_NAME("Bridge.Memory");
MODULE_ENTITY(ModMemory, module) = {
    .alloc = _bridge_memory_alloc,
    .free  = _bridge_memory_free
};
MODULE_ENTITY_GETTER(module);
