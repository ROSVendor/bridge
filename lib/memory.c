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


ret_state get_entity(void ** addrp) {
    *addrp = &module;
    return ES_NORMAL;
}
