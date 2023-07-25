#include <board.h>

PheonixBoard::PheonixBoard() : board(BOARD_SIZE)
{
}

BitBoard PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board[boardType];
}
