cmake_minimum_required(VERSION 3.28)
project(03_Prototypes)

set(CMAKE_CXX_STANDARD 20)

# Configurazione Boost
set(BOOST_ROOT C:\\local\\boost_1_88_0)

# Trova Boost
find_package(Boost REQUIRED COMPONENTS serialization)

# Crea l'eseguibile PRIMA di linkare le librerie
add_executable(03_Prototypes main.cpp)

# Ora puoi linkare le librerie e includere le directory
if(Boost_FOUND)
    target_link_libraries(03_Prototypes ${Boost_LIBRARIES})
    target_include_directories(03_Prototypes PRIVATE ${Boost_INCLUDE_DIRS})
endif()