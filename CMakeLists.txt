cmake_minimum_required(VERSION 4.3)

project(DeudaProject)

add_subdirectory(myLibs/PagosLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(DeudaProject main.cpp)

target_link_libraries(DeudaProject PagosLib)