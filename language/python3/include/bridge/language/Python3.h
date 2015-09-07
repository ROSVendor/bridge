/**
 * Python 3 语言支持的定义
 */
#ifndef BRIDGE_PYTHON3_H
#define BRIDGE_PYTHON3_H

#include <bridge/module.h>
#include <python3.4/Python.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DERIVING_NAMED;
} LangPy3;

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_PYTHON3_H
