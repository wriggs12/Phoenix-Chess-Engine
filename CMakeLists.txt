cmake_minimum_required(VERSION 3.5)

project(
    PHEONIX_ENGINE
    VERSION 1.0
    LANGUAGES CXX   
)

include(CTest)

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
set(LIBRARY_NAME PHEONIX_ENGINE)


add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# add_subdirectory(test)
