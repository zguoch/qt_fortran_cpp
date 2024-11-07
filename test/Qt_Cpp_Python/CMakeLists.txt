cmake_minimum_required(VERSION 3.10)
project(QtFortranExample LANGUAGES C CXX Fortran)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core)

# =====================================================================================
#             configurations
# -------------------------------------------------------------------------------------
include(python)
include(pybind11)

# =====================================================================================

# add_library(my_fortran_code SHARED test.f90)

add_executable(main main.cpp)
 
target_link_libraries(main Qt5::Core pybind11::module Python3::Python)