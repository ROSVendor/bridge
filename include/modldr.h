/**
 * Bridge的模块加载器的定义部分
 */
#ifndef BRIDGE_MODLDR_H
#define BRIDGE_MODLDR_H

#include <include/error.h>
#include <include/module.h>

enum ErrorState load_inner(enum InnerModuleType type, void * mod);

#endif //BRIDGE_MODLDR_H
