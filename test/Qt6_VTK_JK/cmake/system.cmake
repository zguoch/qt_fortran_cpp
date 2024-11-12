if(UNIX AND NOT APPLE)
    # fix static link issue for linux system
    set(LINK_FLAGS "-Wl,--no-as-needed -ldl")
endif()

# set compiler flag
if (APPLE)
  add_definitions("-Wno-array-bounds -Wno-unused-command-line-argument") # turn off this array bound check warning at this moment, this warning accurs at where dim!=3
#   set(CMAKE_OSX_DEPLOYMENT_TARGET 14.0) #used to get rid of the annoying warning: *** was built for newer macOS version (12.0) than being linked (11.3)
endif()

if(WIN32)
    add_compile_options(-w) #取消显示警告信息，太多太烦了
    add_compile_options(-openmp:llvm) #为了使用openmp的task
else()
    add_definitions("-Wno-writable-strings") # This is invalid for MSVC
    add_compile_options(-fPIC) # this option is important of Linux system.
endif()