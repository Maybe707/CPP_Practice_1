cmake_minimum_required(VERSION 3.0.0)
project(MathLib VERSION 0.1.0)

file(GLOB SOURCES *.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(MathLib ${SOURCES})

