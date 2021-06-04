#include <Python.h>

static PyObject *py_randomreal(PyObject *self, PyObject *args){
  double a, b, result;
  const float RAND_MAX_F = RAND_MAX;
  srand (time(NULL));
  float r;
  r = rand();
  if (PyTuple_Size(args) == 0) {
   return Py_BuildValue("d", ((float)((int)r % 100))/100);
    }

  if (PyTuple_Size(args) != 2) {
    PyErr_SetString(PyExc_ValueError,
            "unknown number of variables");
   return NULL;
    }

  if(!PyArg_ParseTuple(args,"dd", &a, &b))
    return NULL;
  result = ((b - a) * (((float)((int)r % 100))/100)) + a;

  return Py_BuildValue("d", result);
}

static PyObject *py_listrandomreal(PyObject *self, PyObject *args){
      PyObject *a, *result;
      int b,  i;
      float res, r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"Oi", &a, &b)){
        return NULL;}

    double *B = (double*)malloc(2 * sizeof(double*));
    for (i = 0; i < 2; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(a, i);
	res = PyFloat_AsDouble(item);
	B[i] = res;
    }
    double *X = (double*)malloc(b * sizeof(double*));
    for (i = 0; i < b; i++){
        r = rand();
        X[i] = (double)(((B[1] - B[0]) * (((float)((int)r % 100))/100)) + B[0]);

    }
    PyObject *my_list = PyList_New(b);
    for (i = 0; i < b; i++)
	PyList_SET_ITEM(my_list, i, PyFloat_FromDouble(X[i]));
    return my_list;

}

static PyObject *py_listlistrandomreal(PyObject *self, PyObject *args){
      PyObject *a, *b;
      int  i,j, L;
      float res, r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"OO", &a, &b)){
        return NULL;}

    double *A = (double*)malloc(2 * sizeof(double*));
    for (i = 0; i < 2; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(a, i);
	res = PyFloat_AsDouble(item);
	A[i] = res;
    }
    L = PyList_GET_SIZE(b);
    double *B = (double*)malloc(L * sizeof(double*));
        for (i = 0; i < L; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(b, i);
	res = PyFloat_AsDouble(item);
	B[i] = res;
    }
    double **X = (double*)malloc(B[0] * sizeof(double*));
    for (i = 0; i < B[0]; i++){
	X[i] = (double*)malloc(B[1] * sizeof(double));
	}
	for (j = 0; j < B[0]; j++){
    for (i = 0; i < B[1]; i++){
        r = rand();
        X[j][i] = (double)(((A[1] - A[0]) * (((float)((int)r % 100))/100)) + A[0]);
    }
	}
 	PyObject *my_list = PyList_New(0);
    	for (i=0; i<B[0]; i++){
		PyObject *new_list = PyList_New(B[1]);
		for (int j=0; j<B[1]; j++)
			{
	   		PyObject *the_object = PyFloat_FromDouble(X[i][j]);
	   		PyList_SetItem(new_list, j, the_object);
			}

	PyList_Append(my_list, new_list);
    			}

    return my_list;

}



/*Integer*/

static PyObject *py_randomint(PyObject *self, PyObject *args){
  int a, b, result;
  const float RAND_MAX_F = RAND_MAX;
  srand (time(NULL));
  float r;
  r = rand();
  if (PyTuple_Size(args) == 0) {
   return Py_BuildValue("i", (int)(((int)r % 100))/10);
    }

  if (PyTuple_Size(args) != 2) {
    PyErr_SetString(PyExc_ValueError,
            "unknown number of variables");
   return NULL;
    }

  if(!PyArg_ParseTuple(args,"ii", &a, &b))
    return NULL;
  result = (int)(((b - a) * (((float)((int)r % 100))/100)) + a);

  return Py_BuildValue("i", result);
}

static PyObject *py_listrandomint(PyObject *self, PyObject *args){
      PyObject *a, *result;
      int b,  i;
      float res, r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"Oi", &a, &b)){
        return NULL;}

    int *B = (int*)malloc(2 * sizeof(int*));
    for (i = 0; i < 2; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(a, i);
	res = PyFloat_AsDouble(item);
	B[i] = res;
    }
    int *X = (int*)malloc(b * sizeof(int*));
    for (i = 0; i < b; i++){
        r = rand();
        X[i] = (int)(((B[1] - B[0]) * (((float)((int)r % 100))/100)) + B[0]);
    }
    PyObject *my_list = PyList_New(b);
    for (i = 0; i < b; i++)
	PyList_SET_ITEM(my_list, i, PyLong_FromLong(X[i]));
    return my_list;

}

static PyObject *py_listlistrandomint(PyObject *self, PyObject *args){
      PyObject *a, *b;
      int  i,j, L;
      float res, r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"OO", &a, &b)){
        return NULL;}

    double *A = (int*)malloc(2 * sizeof(int*));
    for (i = 0; i < 2; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(a, i);
	res = PyFloat_AsDouble(item);
	A[i] = res;
    }
    L = PyList_GET_SIZE(b);
    double *B = (int*)malloc(L * sizeof(int*));
        for (i = 0; i < L; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(b, i);
	res = PyFloat_AsDouble(item);
	B[i] = res;
    }
    int **X = (int*)malloc(B[0] * sizeof(int*));
    for (i = 0; i < B[0]; i++){
	X[i] = (int*)malloc(B[1] * sizeof(int));
	}
	for (j = 0; j < B[0]; j++){
    for (i = 0; i < B[1]; i++){
        r = rand();
        X[j][i] = (int)(((A[1] - A[0]) * (((float)((int)r % 100))/100)) + A[0]);
    }
	}
 	PyObject *my_list = PyList_New(0);
    	for (i=0; i<B[0]; i++){
		PyObject *new_list = PyList_New(B[1]);
		for (int j=0; j<B[1]; j++)
			{
	   		PyObject *the_object = PyLong_FromLong(X[i][j]);
	   		PyList_SetItem(new_list, j, the_object);
			}

	PyList_Append(my_list, new_list);
    			}

    return my_list;

}

static PyObject *py_randomchoice(PyObject *self, PyObject *args){
      PyObject *a, *result;
      int b,  i, L,  pos;
      float r;
      srand (time(NULL));
if (PyTuple_Size(args) == 1) {
    if(!PyArg_ParseTuple(args,"O", &a)){
        return NULL;
    }
    L = PyList_GET_SIZE(a);
    r = rand();
    pos = (int)(((L) * (((float)((int)r % 100))/100)));
    return PySequence_Fast_GET_ITEM(a, pos);

}
if(!PyArg_ParseTuple(args,"Oi", &a, &b)){
return NULL;
}
    L = PyList_GET_SIZE(a);
    PyObject *my_list = PyList_New(b);
    PyObject *py_list = PyList_New(L);
    for (i = 0; i < L; i++){
	PyList_SET_ITEM(py_list, i, PySequence_Fast_GET_ITEM(a, i));
    }
    for (i = 0; i < b; i++){
    r = rand();
    pos = (int)(((L) * (((float)((int)r % 100))/100)));
	PyList_SET_ITEM(my_list, i, PySequence_Fast_GET_ITEM(a, pos));
    }

    return my_list;
}

static PyObject *py_listrandomchoice(PyObject *self, PyObject *args){
      PyObject *a, *b;
      int   i, res,  bi, bl,  pos, L, LL;
      float r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"OO", &a, &b)){
        return NULL;}
    L = PyList_GET_SIZE(a);
    LL = PyList_GET_SIZE(b);
    double *B = (double*)malloc(LL * sizeof(double*));
        for (i = 0; i < LL; i++){
  	PyObject *item = PySequence_Fast_GET_ITEM(b, i);
	res = PyLong_AsLong(item);
	B[i] = res;
    }
 	PyObject *my_list = PyList_New(0);
    for (i=0; i<B[0]; i++){
		PyObject *new_list = PyList_New(B[1]);
		for (int j=0; j<B[1]; j++)
			{
			 r = rand();
            pos = (int)(((L) * (((float)((int)r % 100))/100)));
	   		PyObject *the_object = PySequence_Fast_GET_ITEM(a, pos);
	   		PyList_SetItem(new_list, j, the_object);
			}

	PyList_Append(my_list, new_list);
    			}


return my_list;
}


static PyObject *py_randomsample(PyObject *self, PyObject *args){
      PyObject *a,  *bi, *bl;
      int   i,b, res,  pos, L, LL;
      float r;
      srand (time(NULL));
if(!PyArg_ParseTuple(args,"Oi", &a, &b)){
return NULL;
}

    L = PyList_GET_SIZE(a);
    PyObject *new_list = PyList_New(b);
    int *B = (int*)malloc(L * sizeof(int*));
        for (i = 0; i < L; i++){
            B[i] = i;
    }
    for (int i = L - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);

        int tmp = B[j];
        B[j] = B[i];
        B[i] = tmp;
    }
        for (int j=0; j<b; j++)
			{
	   		PyObject *the_object = PySequence_Fast_GET_ITEM(a, B[j]);
	   		PyList_SetItem(new_list, j, the_object);
			}

    return new_list;
}


static PyObject *py_randomshuffle(PyObject *self, PyObject *args){
      PyObject *a,  *bi, *bl;
      int   i, res,  pos, L, LL;
      float r;
      srand (time(NULL));
    if(!PyArg_ParseTuple(args,"O", &a)){
        return NULL;}

    L = PyList_GET_SIZE(a);
    int b = L;
    PyObject *new_list = PyList_New(b);
    int *B = (int*)malloc(L * sizeof(int*));
        for (i = 0; i < L; i++){
            B[i] = i;
    }
    for (int i = L - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);

        int tmp = B[j];
        B[j] = B[i];
        B[i] = tmp;
    }
        for (int j=0; j<b; j++)
			{
	   		PyObject *the_object = PySequence_Fast_GET_ITEM(a, B[j]);
	   		PyList_SetItem(new_list, j, the_object);
			}

    return new_list;
}





/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "randomreal",          // название функции внутри python
     py_randomreal,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "listrandomreal",          // название функции внутри python
     py_listrandomreal,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "listlistrandomreal",          // название функции внутри python
     py_listlistrandomreal,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "randomint",          // название функции внутри python
     py_randomint,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "listrandomint",          // название функции внутри python
     py_listrandomint,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "listlistrandomint",          // название функции внутри python
     py_listlistrandomint,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "randomchoice",          // название функции внутри python
     py_randomchoice,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "listrandomchoice",          // название функции внутри python
     py_listrandomchoice,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "randomsample",          // название функции внутри python
     py_randomsample,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{
    "randomshuffle",          // название функции внутри python
     py_randomshuffle,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "rand function" // документация для функции внутри python
},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. Сколько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};

/* Описываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "my_rand",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_rand(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
