/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

typedef uint64_t BitBoard;

const int BOARD_SIZE = 12;
enum Piece {
    whitePawn, 
    whiteRook, 
    whiteKnight, 
    whiteBishop, 
    whiteQueen, 
    whiteKing, 
    blackPawn, 
    blackRook, 
    blackKnight, 
    blackBishop, 
    blackQueen,
    blackKing
};

#endif
