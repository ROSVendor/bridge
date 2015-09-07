/**
 * bridge模块的实现
 */
#include <python3.4/Python.h>
#include <python3.4/structmember.h>
#include "../include/bridge/language/PyBridge.h"

static PyMethodDef bridge_methods[] = {
    { "expose", bridge_expose, METH_VARARGS, "expose a Python callable to Bridge Runtime." },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef bridge_module = {
    PyModuleDef_HEAD_INIT,
    "bridge",
    "Bridge's Python wrapping",
    -1,
    bridge_methods
};

PyMODINIT_FUNC PyInit_bridge() {
    PyObject * bridge;
    if (PyType_Ready(&bundle_type) < 0)
        return NULL;
    bridge = PyModule_Create(&bridge_module);
    if (bridge == NULL)
        return NULL;
    Py_INCREF(&bundle_type);
    PyModule_AddObject(bridge, "Bundle", (PyObject *) &bundle_type);
    return bridge;
}
