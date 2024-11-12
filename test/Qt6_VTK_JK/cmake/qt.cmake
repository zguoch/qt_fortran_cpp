set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
set(QT_VERSION_MAJOR 6)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools 
PrintSupport Xml Svg #这是JKQtPlotter需要的
REQUIRED)

# 获取qt的一些变量
if(QT_VERSION_MAJOR EQUAL 6)
    set(QT_VERSION ${Qt6_VERSION})
    set(QT_DIR ${Qt6_DIR})
else()
    set(QT_VERSION ${Qt5_VERSION})
    set(QT_DIR ${Qt5_DIR})
endif()

# set icon
if(APPLE)
    set(logo_icon ${CMAKE_CURRENT_SOURCE_DIR}/Icons/logo.icns)
else()
    set(logo_icon ${CMAKE_CURRENT_SOURCE_DIR}/Icons/logo.rc)
endif()

set(translation_zh "zh_CN")
set(TS_FILES languages/${translation_zh}.ts)

qt_add_translation(QTranslatFiles 
    ${TS_FILES}
)
qt_add_resources(QRC_Srcs 
    Icons/icons.qrc
)