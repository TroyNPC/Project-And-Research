#include <Python.h>  // Include the Python header

int main() {
    // Initialize the Python Interpreter
    Py_Initialize();

    // Check if the Python interpreter was initialized successfully
    if (!Py_IsInitialized()) {
        return -1;
    }

    // Execute Python code directly as a string
    const char* code = 
        "def add_numbers(a, b):\n"
        "    return a + b\n"
        "result = add_numbers(40, 20)\n"
        "print('Result from Python function:', result)";

    // Run the Python code
    PyRun_SimpleString(code);
    
    // Finalize the Python Interpreter
    Py_Finalize();
    
    return 0;
}
