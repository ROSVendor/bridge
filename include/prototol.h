/**
 * 调用协议
 */
#ifndef BRIDGE_PROTOTOL_H
#define BRIDGE_PROTOTOL_H

#include <include/language.h>
#include <include/typesystem.h>
#include <include/env.h>

typedef struct {
    int srcc;
    int argc;
    const char ** srcv;
    const void ** argv;
} CallArgs;

/**
 * 面向C用户的最终调用
 */
void * foreign_call(Env*, Family*, Runtime*, CallArgs*);

/**
 * 类型互换
 * 不支持两个外部语言之间的相互转换，必须使用C语言桥接
 * 这会降低性能，但是总线架构能有效地抑制复杂度
 */
void   * cast_to_foreign(Family*, Runtime*, CValue *);
CValue * cast_to_native (Family*, Runtime*, void   *);
#endif //BRIDGE_PROTOTOL_H
