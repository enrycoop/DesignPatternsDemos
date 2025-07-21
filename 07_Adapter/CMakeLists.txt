cmake_minimum_required(VERSION 3.16)
project(ImGuiHelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova i pacchetti necessari
if(UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW3 REQUIRED glfw3)
else ()
    find_package(glfw3 CONFIG REQUIRED)
endif ()
find_package(OpenGL REQUIRED)

# File sorgenti ImGui
set(IMGUI_SOURCES
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
)

# Include directories
include_directories(imgui)
include_directories(imgui/backends)
include_directories(${GLFW3_INCLUDE_DIRS})

# Crea l'eseguibile
add_executable(${PROJECT_NAME}
        main.cpp
        ${IMGUI_SOURCES}
)
target_link_libraries(ImGuiHelloWorld )
# Link alle librerie
target_link_libraries(${PROJECT_NAME} PRIVATE glfw
        OpenGL::GL
)

# Compilatore flags per debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
endif()