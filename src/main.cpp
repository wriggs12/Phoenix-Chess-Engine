#include <board.h>
#include <iostream>

int main(int argc, char* argv[])
{
    PheonixBoard b;

    Move m = {
        8,        // Start Square
        40,       // End Square
        WHITEPAWN // Piece
    };

    std::cout << b << std::endl;

    b.move(m);

    std::cout << b << std::endl;

    return 0;
}