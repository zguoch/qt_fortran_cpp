cmake_minimum_required(VERSION 3.10)
project(QtFortranExample LANGUAGES C CXX Fortran)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

# add_library(my_fortran_code SHARED test.f90)

add_executable(main main.cpp test.f90)
 
target_link_libraries(main Qt6::Core)
