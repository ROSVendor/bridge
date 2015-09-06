/**
 * 综合头文件
 */
#ifndef BRIDGE_BRIDGE_H
#define BRIDGE_BRIDGE_H

#include <stdbool.h>
#include <stddef.h>
#include <iso646.h>
#include <bridge/entity.h>
#include <bridge/prototol.h>
#include <bridge/language.h>
#include <bridge/error.h>
#include <bridge/macro.h>
#include <bridge/module.h>
#include <bridge/modloader.h>

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
