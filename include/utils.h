/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <unordered_map>
#include <string>

typedef uint64_t BitBoard;
static const int BOARD_SIZE = 12;

#define DEFAULT_POSITION std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkg - 0 1") //FEN format

enum Piece : uint8_t {
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

const std::unordered_map<Piece, char> pieceLetterMap = {
    {WHITEROOK, 'r'},
    {WHITEKNIGHT, 'n'},
    {WHITEBISHOP, 'b'},
    {WHITEQUEEN, 'q'},
    {WHITEKING, 'k'},
    {WHITEPAWN, 'p'},
    {BLACKPAWN, 'P'},
    {BLACKROOK, 'R'},
    {BLACKKNIGHT, 'N'},
    {BLACKBISHOP, 'B'},
    {BLACKQUEEN, 'Q'},
    {BLACKKING, 'K'},
    {EMPTY, 'e'}
};

const std::unordered_map<int, Piece> numPieceMap = {
    {0, WHITEPAWN},
    {1, WHITEROOK},
    {2, WHITEKNIGHT},
    {3, WHITEBISHOP},
    {4, WHITEQUEEN},
    {5, WHITEKING},
    {6, BLACKPAWN},
    {7, BLACKROOK},
    {8, BLACKKNIGHT},
    {9, BLACKBISHOP},
    {10, BLACKQUEEN},
    {11, BLACKKING}
};

struct Square {
    char file;
    int rank;
};

struct FEN {
    std::string fen;
    std::unordered_map<Color, std::pair<bool, bool>> castlingRights;
    Color currentMove;
    Square enPassantSquare;
    int halfMoves;
    int fullMoves;
};

struct Move {
    Square start;
    Square end;
};

#endif
