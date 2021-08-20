#include <Python.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>

#ifndef RENAME_EXCHANGE
#define RENAME_EXCHANGE 2
#endif

static PyObject* _rename_exchange(PyObject* self, PyObject* args) {
  char* path1_char = NULL;
  char* path2_char = NULL;

  if (!PyArg_ParseTuple(args, "s|s", &path1_char, &path2_char)) {
    return NULL;
  };

  if (!syscall(SYS_renameat2, AT_FDCWD, path1_char, AT_FDCWD, path2_char,
               RENAME_EXCHANGE)) {
    return PyUnicode_FromString("Completed Successfully");
  } else {
    perror(NULL);
    return PyUnicode_FromString("Please check to see if the directory exists.");
  };
}

static struct PyMethodDef methods[] = {
    {"rename_exchange", (PyCFunction)_rename_exchange, METH_VARARGS,
     "atomically switches two dirs"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef module = {PyModuleDef_HEAD_INIT, "_rename_exchange",
                                    NULL, -1, methods};

PyMODINIT_FUNC PyInit__rename_exchange(void) {
  return PyModule_Create(&module);
}
