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

set(LIBRARY_NAME PHEONIX_ENGINE)

set(TEST_NAME UNIT_TESTS)

SET(TEST_SOURCES
    test/main.cpp
)

add_library(${LIBRARY_NAME} STATIC ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# enable_testing()
# add_executable(${TEST_NAME} ${TEST_SOURCES})

# target_link_libraries(${TEST_NAME} PUBLIC ${LIBRARY_NAME})