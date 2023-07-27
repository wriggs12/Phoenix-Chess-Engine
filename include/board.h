/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utils.h>

class PheonixBoard {
    public:
        PheonixBoard(const std::string& fen = DEFAULT_POSITION);
        PheonixBoard(const PheonixBoard& other);
        BitBoard getPieceBoard(Piece boardType) const;

    private:
        void loadFEN(const std::string& fen);
        void printBitBoard();

    private:
        std::vector<BitBoard> board = std::vector<BitBoard>(BOARD_SIZE, 0);
        Color currentMove;
};

#endif
