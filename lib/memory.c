/**
 * 对Bridge.Memory的默认实现的封装
 */


#include <include/module.h>
#include <include/memory.h>
#include <include/_memory.h>

static ModMemory module = {
    .name  = "Bridge.Memory",
    .alloc = _bridge_memory_alloc,
    .free  = _bridge_memory_free
};

MODULE_ENTITY(ModMemory, module);
