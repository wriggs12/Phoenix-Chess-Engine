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
        PheonixBoard();
        BitBoard getPieceBoard(Piece boardType) const;

    private:
        std::vector<BitBoard> board;
};

#endif