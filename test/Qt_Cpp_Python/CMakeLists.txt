cmake_minimum_required(VERSION 3.10)
project(QtFortranExample LANGUAGES C CXX Fortran)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
# ----------------默认设置 ------------------------------------
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install) 
set(Python3_EXECUTABLE "/Users/zguo/MyData/Research/1-OpenSourceCode/Python-3.13.0_static/bin/python3")
# -------------------------------------------

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

add_executable(${PROJECT_NAME} main.cpp)
 
target_link_libraries(${PROJECT_NAME} Qt5::Core pybind11::module ${Python3_LIBRARIES})
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_SOURCE_DIR}/python/test.py DESTINATION ${CMAKE_INSTALL_PREFIX}/python)