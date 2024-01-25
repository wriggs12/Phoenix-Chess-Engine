#include <board.h>
#include <iostream>

int main()
{
    PheonixBoard b;

    Move m;
    m.start = 8;
    m.end = 16;
    m.piece = WHITEPAWN;

    b.move(m);

    return 0;
}