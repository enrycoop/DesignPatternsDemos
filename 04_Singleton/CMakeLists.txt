cmake_minimum_required(VERSION 3.29)
project(04_Singleton)

find_package(Boost REQUIRED COMPONENTS lexical_cast)
find_package(GTest CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_Singleton main.cpp)

target_link_libraries(04_Singleton PRIVATE
        Boost::lexical_cast
        GTest::gtest
        GTest::gtest_main
)


