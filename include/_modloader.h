/**
 * Bridge.ModLoader的默认实现的定义
 */

#ifndef BRIDGE__MODLOADER_H
#define BRIDGE__MODLOADER_H

#include <include/error.h>
#include <include/macro.h>

ret_state _bridge_modloader_require(void **, const char *);
ret_state _bridge_modloader_remove(const void *);

#endif //BRIDGE__MODLOADER_H
