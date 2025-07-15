cmake_minimum_required(VERSION 3.29)
project(04_Singleton_DI)

find_package(Boost REQUIRED COMPONENTS lexical_cast)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_Singleton_DI di.h main.cpp)


target_link_libraries(04_Singleton_DI PRIVATE
        Boost::lexical_cast
)