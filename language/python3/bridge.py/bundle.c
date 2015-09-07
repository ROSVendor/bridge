/**
 * bridge.Bundle类的实现
 */
#include <python3.4/Python.h>
#include <python3.4/structmember.h>
#include "../include/bridge/language/PyBridge.h"

PyTypeObject bundle_type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name      = "bridge.Bundle",
    .tp_basicsize = sizeof(BundleType),
    .tp_flags     = Py_TPFLAGS_DEFAULT,
    .tp_doc       = "Bridge bundle",
    .tp_dealloc   = (destructor) bundle_dealloc,
    .tp_new       =              bundle_new,
    .tp_init      = (initproc)   bundle_init,
    .tp_members   =              bundle_members,
    .tp_methods   =              bundle_methods,
};

#define _offset(field) offsetof(BundleType, field)
PyMemberDef bundle_members[] = {
    { "callable", T_OBJECT_EX, _offset(callable), 0, "callable to expose" },
    { "args",     T_OBJECT,    _offset(args),     0, "arg types" },
    { NULL }
};
#undef _offset

PyMethodDef bundle_methods[] = {
    { NULL }
};
