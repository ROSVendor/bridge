/**
 * 对Bridge.Memory的默认实现的封装
 */


#include <include/module.h>
#include <include/memory.h>
#include <include/_memory.h>

MODULE_NAME("Bridge.Memory");
MODULE_ENTITY(ModMemory, module) = {
    .alloc = _bridge_memory_alloc,
    .free  = _bridge_memory_free
};
MODULE_ENTITY_GETTER(module);
