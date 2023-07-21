#include <board.h>

PheonixBoard::PheonixBoard() : board(BOARD_SIZE)
{
}

const BitBoard PheonixBoard::getPieceBoard(Piece boardType)
{
    return board[boardType];
}