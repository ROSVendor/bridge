/**
 * bridge模块级别的函数实现
 */

#include <python3.4/Python.h>
#include <python3.4/structmember.h>
#include "../include/bridge/language/PyBridge.h"

PyObject * bridge_expose(PyObject * self, PyObject * args) {
    PyObject * callable = NULL;
    int argc = 0;
    if (!PyArg_ParseTuple(args, "oi", &callable, &argc))
        return NULL;
    return Py_None;
}

