#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <board.h>
#include "spdlog/spdlog.h"

TEST_CASE("Default/Copy Constructor")
{
    PheonixBoard a;
    PheonixBoard b(a);

    spdlog::info("a: " + a.getFenBoard());
    spdlog::info("b: " + b.getFenBoard());

    CHECK(a.getFenBoard() == b.getFenBoard());
}

TEST_CASE("Copy Operator")
{
    const std::string fen = "rnbqkbnr/pppp1ppp/4p3/8/8/8/PPPPPPPP/RNBQKBNR w KQkg - 0 1";
    
    PheonixBoard a(fen);
    PheonixBoard b;

    b = a;

    spdlog::info("a: " + a.getFenBoard());
    spdlog::info("b: " + b.getFenBoard());

    CHECK(a.getFenBoard() == b.getFenBoard());
    CHECK(a == b);
}