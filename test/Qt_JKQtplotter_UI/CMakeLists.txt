cmake_minimum_required(VERSION 3.23)

set(EXAMPLE_NAME ui)
set(EXENAME jkqtptest_${EXAMPLE_NAME})

message( STATUS "..   Building Example ${EXAMPLE_NAME}" )

set(QT_VERSION_MAJOR 6)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets PrintSupport Svg Xml OpenGL REQUIRED)
 
 
# include JKQTPlotter
find_package(JKQTPlotter${QT_VERSION_MAJOR} REQUIRED)
include_directories(/Users/zguo/MyData/Research/1-OpenSourceCode/JKQTPlotter/Qt6_static_release/include)
 include_directories(/Users/zguo/MyData/Research/3-CodeProject/JKQtPlotter/examples/libexampletools)
 link_directories(/Users/zguo/MyData/Research/3-CodeProject/JKQtPlotter/build/examples/libexampletools)

# Set up source files
set(SOURCES ${EXAMPLE_NAME}.cpp formwithjkqtplotter.cpp)
set(HEADERS formwithjkqtplotter.h)
set(RESOURCES  )
set(UIS formwithjkqtplotter.ui )

add_executable(${EXENAME} WIN32 ${SOURCES} ${HEADERS} ${RESOURCES} ${UIS})
target_link_libraries(${EXENAME} JKQTPExampleToolsLib Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::PrintSupport Qt${QT_VERSION_MAJOR}::Svg Qt${QT_VERSION_MAJOR}::Xml)
target_include_directories(${EXENAME} PRIVATE ../../lib)
target_link_libraries(${EXENAME} ${jkqtplotter_namespace}JKQTPlotter${jkqtplotter_LIBNAME_VERSION_PART})

# precomiled headers to speed up compilation
if (JKQtPlotter_BUILD_WITH_PRECOMPILED_HEADERS)
  target_precompile_headers(${EXENAME} REUSE_FROM jkqtptest_simpletest)
endif (JKQtPlotter_BUILD_WITH_PRECOMPILED_HEADERS)



# Installation
install(TARGETS ${EXENAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

#Installation of Qt DLLs on Windows
# jkqtplotter_deployqt(${EXENAME})
