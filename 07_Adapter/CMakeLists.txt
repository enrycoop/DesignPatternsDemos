cmake_minimum_required(VERSION 3.29)
project(07_Adapter)

set(CMAKE_CXX_STANDARD 20)

find_package(FLTK REQUIRED)

add_executable(07_Adapter main.cpp
        Geometry.h graphics_gui.h graphics_gui.cxx)
target_link_libraries(07_Adapter PRIVATE fltk)
