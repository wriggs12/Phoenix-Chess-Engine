#include <gtest/gtest.h>
#include <board.h>

TEST(board, constructor)
{
    PhoenixBoard b1{};
    PhoenixBoard b2{};

    ASSERT_TRUE(b1.isDraw() == b2.isDraw());

}