find_package(pybind11 REQUIRED)
message(STATUS "pybind11 include: ${pybind11_INCLUDE_DIRS}")
include_directories(${pybind11_INCLUDE_DIRS})
message(STATUS "pybind11 library: ${pybind11_LIBRARIES}")