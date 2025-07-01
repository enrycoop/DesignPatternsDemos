cmake_minimum_required(VERSION 3.26)
project(01_builderFacets)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_builderFacets main.cpp
        Person.cpp
        Person.h
        PersonBuilder.cpp
        PersonBuilder.h
        PersonAddressBuilder.h
        PersonJobBuilder.h
)
