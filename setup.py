from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'my_cpp_lib',  # Name of the resulting Python module
        sources=['pymod.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++',
        extra_compile_args=["-std=c++17"]
    ),
]

setup(
    name='my_python_package',
    version='1.0',
    description='A package with a C++ extension',
    ext_modules=ext_modules,
    # Ensure pybind11 is installed before this runs
    install_requires=['pybind11']
)
