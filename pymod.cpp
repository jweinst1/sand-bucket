#include <pybind11/pybind11.h>
#include "murmur3.h"

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;


uint32_t murmur3_32_py(py::buffer buf, uint32_t seed = 0) {
    py::buffer_info info = buf.request(false);  // false = read-only request


    return murmur3_32(info.ptr, info.size, seed);
}

uint64_t murmur3_64_py(py::buffer buf, uint64_t seed = 0) {
    py::buffer_info info = buf.request(false);  // false = read-only request


    return murmur3_64(info.ptr, info.size, seed);
}

PYBIND11_MODULE(my_cpp_lib, m) {
    m.def("murmur3_32",
          py::overload_cast<py::buffer, uint32_t>(&murmur3_32_py),
          py::arg("data"),
          py::arg("seed") = 0,
          "Compute 32-bit MurmurHash3 on any buffer-like object (bytes, bytearray, memoryview, numpy array, ...) without copying");
    m.def("murmur3_64",
          py::overload_cast<py::buffer, uint64_t>(&murmur3_64_py),
          py::arg("data"),
          py::arg("seed") = 0,
          "Compute 64-bit MurmurHash3 on any buffer-like object (bytes, bytearray, memoryview, numpy array, ...) without copying");
    m.def("add", &add, "A function that adds two numbers");
}
