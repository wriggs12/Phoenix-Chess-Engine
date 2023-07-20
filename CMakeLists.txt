cmake_minimum_required(VERSION 3.5)

project(PheonixEngine)

enable_testing()

add_library(PheonixEngineLib
    src/board.cpp
    src/engine.cpp
    src/pieces.cpp
    src/utils.h
)

target_include_directories(PheonixEngineLib PUBLIC ./)

add_executable(PheonixEngine testing.cpp)

target_link_libraries(PheonixEngine PRIVATE PheonixEngineLib)