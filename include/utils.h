/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <unordered_map>

typedef uint64_t BitBoard;
static const int BOARD_SIZE = 12;

#define DEFAULT_POSITION std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkg - 0 1") //FEN format

enum Piece {
    WHITEPAWN,
    WHITEROOK,
    WHITEKNIGHT,
    WHITEBISHOP,
    WHITEQUEEN,
    WHITEKING,
    BLACKPAWN,
    BLACKROOK,
    BLACKKNIGHT,
    BLACKBISHOP,
    BLACKQUEEN,
    BLACKKING,
    EMPTY
};

enum Color : uint8_t {
    WHITE,
    BLACK
};

const std::unordered_map<char, Piece> pieceMap = {
    {'r', WHITEROOK},
    {'n', WHITEKNIGHT},
    {'b', WHITEBISHOP},
    {'q', WHITEQUEEN},
    {'k', WHITEKING},
    {'p', WHITEPAWN},
    {'P', BLACKPAWN},
    {'R', BLACKROOK},
    {'N', BLACKKNIGHT},
    {'B', BLACKBISHOP},
    {'Q', BLACKQUEEN},
    {'K', BLACKKING}
};

#endif
