#include <board.h>
#include <iostream>

int main()
{
    PheonixBoard *b = new PheonixBoard();
    std::cout << *b << '\n';
    return 0;
}