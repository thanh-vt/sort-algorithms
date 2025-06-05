cmake_minimum_required(VERSION 3.30)
project(sort-algorithms)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(sort-algorithms ${SRC})
