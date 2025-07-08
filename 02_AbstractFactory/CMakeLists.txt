cmake_minimum_required(VERSION 3.2)
project(02_AbstractFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(02_AbstractFactory main.cpp
        HotDrink.h
        HotDrinkFactory.h
        DrinkFactory.h)
