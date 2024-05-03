cmake_minimum_required(VERSION 3.5)

project(
    PHOENIX_ENGINE
    VERSION 1.0
    LANGUAGES CXX   
)

set(SOURCES
    src/board.cpp
    src/engine.cpp
    src/evaluate.cpp
    src/moveManager.cpp
    src/play.cpp
    src/loguru.cpp
)

set(TESTS
    test/test_board.cpp
)

set(LIBRARY_NAME PHOENIX_ENGINE)
set(TEST_NAME ${LIBRARY_NAME}_tests)

add_library(${LIBRARY_NAME} STATIC ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(run src/main.cpp)
target_link_libraries(run PUBLIC ${LIBRARY_NAME})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(BUILD_GMOCK OFF CACHE BOOL "")
set(BUILD_GTEST OFF CACHE BOOL "")
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_NAME} ${TESTS})
target_link_libraries(${TEST_NAME} gtest_main ${LIBRARY_NAME})

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
