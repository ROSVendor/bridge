/**
 * 默认的底层内存管理实现
 */
#ifndef BRIDGE_MEMORY_STATIC_H
#define BRIDGE_MEMORY_STATIC_H

#include <include/error.h>
#include <include/macro.h>

#ifdef __cplusplus
extern "C" {
#endif

ret_state _bridge_memory_alloc(size_t size, void ** p);
ret_state _bridge_memory_free(void * p);

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_MEMORY_STATIC_H
