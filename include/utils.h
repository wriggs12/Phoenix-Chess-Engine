/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

#define DEFAULT_POSITION std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkg - 0 1") //fen format

typedef uint64_t BitBoard;

const int BOARD_SIZE = 12;

enum Piece : uint8_t {
    WHITEPAWN,
    WHITEROOK,
    WHITEKNIGHT,
    WHITEBISHOP,
    WHITEQUEEN,
    WHITEKING,
    BLACKPAWN,
    BLACKROOK,
    BLACKKINGHT,
    BLACKBISHOP,
    BLACKQUEEN,
    BLACKKING,
    EMPTY
};

#endif
