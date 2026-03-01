#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(my_cpp_lib, m) {
    m.def("add", &add, "A function that adds two numbers");
}
