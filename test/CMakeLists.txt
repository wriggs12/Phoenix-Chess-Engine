add_executable(testing main.cpp)

target_link_libraries(testing PRIVATE 
    pheonix_eninge_lib
    gtest_main
)
