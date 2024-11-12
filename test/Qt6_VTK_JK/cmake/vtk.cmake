if(NOT USE_VTK)
    return()
endif()

set(VTK_DIR=$ENV{VTK_DIR})
message(STATUS "VTK_DIR: " $ENV{VTK_DIR})
if($ENV{VTK_DIR})
    set(VTK_DIR=$ENV{VTK_DIR})
    message(STATUS "VTK_DIR FOUND: " ${VTK_DIR})
endif()
find_package(VTK COMPONENTS
        CommonCore
        FiltersCore
        InfovisCore
        InteractionStyle
        ViewsQt
        ChartsCore
        CommonDataModel
        RenderingContext2D
        RenderingContextOpenGL2
        RenderingCore
        RenderingFreeType
        RenderingGL2PSOpenGL2
        RenderingOpenGL2
        ViewsContext2D
        IOLegacy 
        RenderingAnnotation
        )
if(VTK_FOUND)
    message(STATUS "VTK version: " "${VTK_VERSION}")
    message(STATUS "VTK QT version: " "${VTK_QT_VERSION}")
    # include(${VTK_USE_FILE}) #is no longer used starting with 8.90
    if("${VTK_VERSION}" STREQUAL "")
        message(FATAL_ERROR "Could not find VTK")
    else()
        
    endif()
    if("${VTK_QT_VERSION}" STREQUAL "")
        message(FATAL_ERROR "VTK was not built with Qt")
    else()
        
    endif()
else()
    message(FATAL_ERROR "VTK is not found")
endif()