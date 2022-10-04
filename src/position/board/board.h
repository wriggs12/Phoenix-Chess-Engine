#ifndef BOARD_H
#define BOARD_H

#include "../../uils.h"

#include <vector>

class PhoenixBoard {
    public:
        PhoenixBoard();
        PieceType getPieceOnSquare(int sqaure);
        void updateBoard(int startSquare, int endSquare);
        bool hasWhiteKingMoved();
        bool hasBlackKingMoved();
        int getRank(int square);
        int getFile(int square);

    protected:

    private:
        std::vector<std::vector<PieceType>> board;
        bool whiteKingMoved;
        bool blackKingMoved;
};

#endif