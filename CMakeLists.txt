cmake_minimum_required(VERSION 3.5)

project(
    PHEONIX_ENGINE
    VERSION 1.0
    LANGUAGES CXX   
)

option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                        Tests in tests/*.cpp will still be enabled." ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(CTest)
include(Doctest)

set(SOURCES
    src/board.cpp
    src/engine.cpp
    src/evaluate.cpp
    src/moveManager.cpp
    src/play.cpp
)

set(TESTFILES
    tests/main.cpp
)
set(LIBRARY_NAME engine)


add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC doctest)

add_subdirectory(test)