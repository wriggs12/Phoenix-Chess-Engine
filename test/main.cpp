#include <board.h>
#include "spdlog/spdlog.h"

void Test()
{
    PheonixBoard a;
    PheonixBoard b(a);

    spdlog::info("a: " + a.getFenBoard());
    spdlog::info("b: " + b.getFenBoard());

    assert(a.getFenBoard() == b.getFenBoard());
}

// TEST_CASE("Copy Operator")
// {
//     const std::string fen = "rnbqkbnr/pppp1ppp/4p3/8/8/8/PPPPPPPP/RNBQKBNR w KQkg - 0 1";
    
//     PheonixBoard a(fen);
//     PheonixBoard b;

//     b = a;

//     spdlog::info("a: " + a.getFenBoard());
//     spdlog::info("b: " + b.getFenBoard());

//     CHECK(a.getFenBoard() == b.getFenBoard());
//     CHECK(a == b);
// }

// int main()
// {
//     PheonixBoard *b = new PheonixBoard();
//     Move m = {
//         0,
//         16,
//         WHITEROOK
//     };
//     b->move(m);

//     return 0;
// }