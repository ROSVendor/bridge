/**
 * 综合头文件
 */
#ifndef BRIDGE_BRIDGE_H
#define BRIDGE_BRIDGE_H

#include <stdbool.h>
#include <stddef.h>
#include <iso646.h>
#include <include/entity.h>
#include <include/prototol.h>
#include <include/language.h>
#include <include/error.h>
#include <include/macro.h>
#include <include/module.h>
#include <include/modloader.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DERIVING_NAMED;
} Bridge;

/**
 * 初始化Bridge系统
 */
ret_state bridge_initialize(Bridge * bridge);

/**
 * 清理Bridge系统
 */
ret_state bridge_finalize();

/**
 * 获取Bridge系统入口
 */
ret_state bridge_instance(Bridge * bridge);

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_BRIDGE_H
