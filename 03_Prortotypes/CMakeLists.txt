cmake_minimum_required(VERSION 3.28)
project(03_Prototypes)

set(CMAKE_CXX_STANDARD 20)

# Trova Boost tramite vcpkg
find_package(Boost REQUIRED COMPONENTS serialization)

# Crea l'eseguibile
add_executable(03_Prototypes main.cpp)

# Link con Boost usando i target moderni di vcpkg
target_link_libraries(03_Prototypes PRIVATE 
    Boost::serialization
)