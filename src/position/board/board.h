#ifndef BOARD_H
#define BOARD_H

#include "../../uils.h"

#include <vector>

class PhoenixBoard {
    public:
        PhoenixBoard();
        PieceType getPieceOnSquare(int sqaure);
        bool updateBoard(int startSquare, int endSquare);

    protected:

    private:
        std::vector<std::vector<PieceType>> board;
};

#endif