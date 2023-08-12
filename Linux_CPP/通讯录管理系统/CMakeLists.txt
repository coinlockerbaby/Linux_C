cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(obj)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(obj01 ${MAIN_SRC})