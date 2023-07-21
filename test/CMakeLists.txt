add_executable(testing main.cpp)

target_link_libraries(testing PRIVATE 
    pheonix_eninge_lib
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing)