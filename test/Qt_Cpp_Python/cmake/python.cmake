# have to set Python3_EXECUTABLE using `cmake -DPython3_EXECUTABLE=/path/python`
# e.g.: set(Python3_EXECUTABLE "/Users/zguo/Downloads/python_static/bin/python3")
# 对于上传pypi使用
set(PYPI_TOKEN " " CACHE STRING "Token of PyPi for package publish")
# ---------------------------- Find Python 3 ---------------------------------

find_package(Python3 REQUIRED COMPONENTS Interpreter Development Development.Module)
message(STATUS "Python include: " ${Python3_INCLUDE_DIRS})
message(STATUS "Python libraries: " ${Python3_LIBRARIES})
message(STATUS "Python version: " ${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}.${Python3_VERSION_PATCH})
include_directories(${Python3_INCLUDE_DIRS})

