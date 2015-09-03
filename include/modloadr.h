/**
 * Bridge的模块加载器的定义部分
 */
#ifndef BRIDGE_MODLDR_H
#define BRIDGE_MODLDR_H

#include <include/language.h>
#include <include/error.h>
#include <include/module.h>
#include <include/macro.h>

/**
 * 加载内部模块
 */
ret_state load_inner_mod(enum InnerModuleType type, void * mod);
/**
 * 加载语言实现
 */
ret_state load_inner_lang(enum LanguageFamily, void * mod);

#endif //BRIDGE_MODLDR_H
