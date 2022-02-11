cmake_minimum_required(VERSION 3.20)
project(Matrices C)

set(CMAKE_C_STANDARD 11)

add_executable(Matrices main.c)

add_subdirectory(libs)
target_link_libraries(algorithms)
target_link_libraries(data_structures)