add_library(pheonix_eninge_lib STATIC
    board.cpp
    engine.cpp
    pieces.cpp
    utils.h
)

target_include_directories(pheonix_eninge_lib PUBLIC .)