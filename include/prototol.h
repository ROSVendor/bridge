/**
 * 调用协议
 */
#ifndef BRIDGE_PROTOTOL_H
#define BRIDGE_PROTOTOL_H

#include <include/language.h>
#include <include/typesystem.h>

typedef struct {
    int srcc;
    int argc;
    const char * srcv[];
    const void * argv[];
} CallArgs;

/**
 * 面向C用户的最终调用
 */
void * foreign_call(Env*, Family*, Runtime*, CallArgs*);

#endif //BRIDGE_PROTOTOL_H
