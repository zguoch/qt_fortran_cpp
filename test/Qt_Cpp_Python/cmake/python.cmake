# have to set Python3_EXECUTABLE using `cmake -DPython3_EXECUTABLE=/path/python`
# set(Python3_EXECUTABLE "/Users/zguo/Downloads/python_static/bin/python3")
# ---------------------------- Find Python 3 ---------------------------------

find_package(Python3 REQUIRED COMPONENTS Interpreter Development Development.Module)
message(STATUS "Python include: " ${Python3_INCLUDE_DIRS})
message(STATUS "Python libraries: " ${Python3_LIBRARIES})
message(STATUS "Python version: " ${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}.${Python3_VERSION_PATCH})
# include_directories(${Python3_INCLUDE_DIRS})
# 从 Python3_LIBRARIES 中提取目录路径
get_filename_component(PYTHON_LIB_DIR ${Python3_LIBRARIES} DIRECTORY)
message(STATUS "python lib path: ${PYTHON_LIB_DIR}")

# 将一些必要的库拷贝到安装目录
INSTALL(DIRECTORY ${PYTHON_LIB_DIR}/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}
      # FILES_MATCHING PATTERN "*.py"
      # PATTERN "IAPWS_Others" EXCLUDE
      )
message(STATUS "copy path: ${PYTHON_LIB_DIR}/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}")