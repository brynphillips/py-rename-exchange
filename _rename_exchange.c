#include <Python.h>
#include <fcntl.h>
#include <sys/syscall.h>

static PyObject* _hello_world(PyObject* self) {
  return PyUnicode_FromString("hello hello world");  // python c api
};

static PyObject* _rename_exchange(PyObject* self, PyObject* args) {
  char* path1_char = NULL;
  char* path2_char = NULL;
  if (!PyArg_ParseTuple(args, "s|s", &path1_char, &path2_char)) {
    Py_DECREF(args);
    return NULL;
    //&& syscall(renameat2, AT_FWD, path1, AT_FWD, path2, RENAME_EXCHANGE) fix
    // this
  };

  if (syscall(SYS_renameat2, AT_FDCWD, path1_char, AT_FDCWD, path2_char,
              RENAME_EXCHANGE)) {
    return 1;
  };

  PyObject* ret =
      PyUnicode_FromFormat("path1: %s, path2: %s", path1_char, path2_char);
  return ret;
}

static PyObject* _to_upper_hello(PyObject* self, PyObject* args) {
  PyObject* name;
  if (!PyArg_ParseTuple(args, "U", &name)) {
    return NULL;
  }

  PyObject* upper = PyObject_CallMethod(name, "upper", NULL);
  if (!upper) {
    return NULL;
  }

  PyObject* ret = PyUnicode_FromFormat("hello %U", upper);
  Py_DECREF(upper);
  return ret;
}

static struct PyMethodDef methods[] = {
    {"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
    {"to_upper_hello", (PyCFunction)_to_upper_hello, METH_VARARGS},
    {"rename_exchange", (PyCFunction)_rename_exchange, METH_VARARGS},
    {NULL, NULL}};

static struct PyModuleDef module = {PyModuleDef_HEAD_INIT, "_rename_exchange",
                                    NULL, -1, methods};

PyMODINIT_FUNC PyInit__rename_exchange(void) {
  return PyModule_Create(&module);
}
