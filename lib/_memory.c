/**
 * Bridge的默认内存管理实现
 */

#include <stdlib.h>
#include <bridge/bridge.h>
#include <bridge/_memory.h>

ret_state _bridge_memory_alloc(size_t size, void ** p) {
    void * addr = malloc(size);
    if (!addr) {

    } else {
        *p = addr;
    }
    return ES_NORMAL;
}
ret_state _bridge_memory_free(void *p) {
    free(p);
    return ES_NORMAL;
}


