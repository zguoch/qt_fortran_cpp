if(NOT USE_JKQtPlotter)
    return()
endif()

find_package(JKQTPlotter${QT_VERSION_MAJOR} REQUIRED)
# 获取qt的一些变量
if(QT_VERSION_MAJOR EQUAL 6)
    set(JKQTPlotter_DIR ${JKQTPlotter6_DIR})
else()
    set(JKQTPlotter_DIR ${JKQTPlotter5_DIR})
endif()
# --- 添加 VTK 宏定义，以便在C++代码中判断
add_definitions(-DUSE_JKQtPlotter)