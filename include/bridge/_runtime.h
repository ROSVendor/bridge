/**
 * 运行时系统的C++实现对模块封装导出的函数
 */
#ifndef BRIDGE__RUNTIME_H
#define BRIDGE__RUNTIME_H

#ifdef __cplusplus
extern "C" {
#endif

void       * _bridge_rts_get_domain(const char *);
ModLoader  * _bridge_rts_get_module_loader();
TypeSystem * _bridge_rts_get_type_system();

#ifdef __cplusplus
}
#endif

#endif //BRIDGE__RUNTIME_H
