/**
 * 综合头文件
 */
#ifndef BRIDGE_BRIDGE_H
#define BRIDGE_BRIDGE_H

#include <stdbool.h>
#include <include/prototol.h>
#include <include/language.h>
#include <include/error.h>
#include <include/macro.h>

ret_state bridge_initialize(void *);
ret_state bridge_finalize();

#endif //BRIDGE_BRIDGE_H
