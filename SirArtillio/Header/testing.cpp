#include <Python.h>
#include <iostream>

using namespace std;

int main(){
	Py_Initialize();
	PyRun_SimpleString("print('Hello C++ From python'));
	Py_Finalize();

	return 0;
}