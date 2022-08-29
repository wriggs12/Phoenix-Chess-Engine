#ifndef PIECES_H
#define PIECES_H

#include "../../uils.h"

class Piece {
    public:
        Piece(PieceType t, int s, int v);
        int getSquare();
        int getValue();
        PieceType getType();

    protected:

    private:
        int square;
        int value;
        PieceType type;
};

#endif