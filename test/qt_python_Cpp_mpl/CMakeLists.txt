cmake_minimum_required(VERSION 3.5)

project(qt_python_Cpp_mpl VERSION 0.1 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
# ----------------默认设置 ------------------------------------
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install) 
set(Python3_EXECUTABLE "/Users/zguo/MyData/Research/1-OpenSourceCode/Python-3.13.0_static/bin/python3")
set(pybind11_DIR "/Users/zguo/MyData/Research/1-OpenSourceCode/Python-3.13.0_static/lib/python3.13/site-packages/pybind11/share/cmake/pybind11")
# -------------------------------------------

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =====================================================================================
#             configurations
# -------------------------------------------------------------------------------------
include(python)
include(pybind11)

# =====================================================================================
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

qt_add_executable(qt_python_Cpp_mpl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_link_libraries(qt_python_Cpp_mpl PRIVATE Qt6::Widgets pybind11::module ${Python3_LIBRARIES})

set_target_properties(qt_python_Cpp_mpl PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

qt_finalize_executable(qt_python_Cpp_mpl)
