/**
 * bridge.Bundle类方法实现
 */

#include <python3.4/Python.h>
#include <python3.4/structmember.h>
#include "../include/bridge/language/PyBridge.h"

void bundle_dealloc(BundleType * self) {
    Py_XDECREF(self->callable);
    Py_XDECREF(self->args);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject * bundle_new(PyTypeObject * type, PyObject * args, PyObject * kwds) {
    BundleType * self;
    self = (BundleType *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->callable = Py_None;
        self->args = Py_None;
    }
    return (PyObject *) self;
}

int bundle_init(BundleType * bundle, PyObject * args, PyObject * kwds) {
    PyObject * i_callable;
    PyObject * i_args;
    if (!PyArg_ParseTuple(args, "OO", &i_callable, &i_args)) {
        return -1;
    }
    if (i_callable) {
        Py_INCREF(i_callable);
        Py_DECREF(bundle->callable);
        bundle->callable = i_callable;
    }
    if (i_args) {
        Py_INCREF(i_args);
        Py_DECREF(bundle->args);
        bundle->args = i_args;
    }
    return 0;
}

