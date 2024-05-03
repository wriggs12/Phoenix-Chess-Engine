#include <board.h>
#include <iostream>

int main(int argc, char* argv[])
{
    PhoenixBoard b;

    Move m {
        8,        // Start Square
        40,       // End Square
    };

    b.move(m);

    return 0;
}