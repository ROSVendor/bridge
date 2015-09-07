/**
 * 定义bridge.py的桥接对象bridge.Bundle
 */

#ifndef BRIDGE_PYBRIDGE_H
#define BRIDGE_PYBRIDGE_H

#include <python3.4/Python.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD;
    PyObject * callable; /** 需要导出到BridgeRuntime的callable对象 */
    PyObject * args;     /** callable对象的参数列表, [type] */
} BundleType;

extern PyTypeObject  bundle_type;
extern PyMemberDef   bundle_members[];
extern PyMethodDef   bundle_methods[];

void       bundle_dealloc(BundleType * self);
PyObject * bundle_new(PyTypeObject * type, PyObject * args, PyObject * kwds);
int        bundle_init(BundleType * bundle, PyObject * args, PyObject * kwds);

PyObject * bridge_expose(PyObject * self, PyObject * args);

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_PYBRIDGE_H
