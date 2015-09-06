/**
 * Bridge中的使用的非常量的宏定义
 */

#ifndef BRIDGE_MACRO_H
#define BRIDGE_MACRO_H

#ifdef __cplusplus
extern "C" {
#endif

#define literalof(x) (#x)
#define ret_state enum ErrorState

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_MACRO_H
