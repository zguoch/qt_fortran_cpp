# 0. CMake Minimum version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(AUTHOR "Zhikui Guo")
set(AUTHOR_EMAIL "guozk@sio.org.cn")

project(template_dataVisualization VERSION 0.1 LANGUAGES CXX C)
# set(LIB_NAME "${PROJECT_NAME}")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =====================================================================================
#                            Build Options
# -------------------------------------------------------------------------------------

# --------------------------------------------------------------------------------------

# =====================================================================================
#                            Options
# -------------------------------------------------------------------------------------
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "..." FORCE)
endif()
# --------------------------------------------------------------------------------------

# =====================================================================================
#             configurations
# -------------------------------------------------------------------------------------
include(mainconfig)
# =====================================================================================

add_subdirectory(VTK)
include_directories(
    ${CMAKE_SOURCE_DIR}
    VTK
    JKQTPlotter
    )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${QTranslatFiles}
        ${QRC_Srcs}
        VTK/VTKWidget.cpp
        JKQtPlotter/JKQTPlotterWidget.cpp
)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})
# test: disable macos bundle, cancle it after debug
set(ENABLE_OS_SPECIFIC_INSTALL ON)
if(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)
    message(STATUS "Configure for macOS install")
    set_target_properties(${PROJECT_NAME} PROPERTIES 
    MACOSX_BUNDLE ON
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
    MACOSX_BUNDLE_ICON_FILE logo.icns
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )
    set_source_files_properties(${QON_QM_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources/translations")
    set_source_files_properties(${logo_icon} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    )

# =============== 使用JKQtPlotter ===============
if(USE_JKQtPlotter)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    JKQTPlotter${QT_VERSION_MAJOR}::JKQTPlotter${QT_VERSION_MAJOR}
)
endif()
# =============== 使用VTK ==============
if(USE_VTK)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    ${VTK_LIBRARIES}
)
    # 必须的
    vtk_module_autoinit(
        TARGETS ${PROJECT_NAME}
        MODULES VTK::ChartsCore
        VTK::InfovisCore
        VTK::ViewsContext2D
        VTK::RenderingContextOpenGL2
        )
endif()
# =======================================

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
