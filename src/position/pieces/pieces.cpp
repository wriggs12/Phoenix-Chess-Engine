#include "pieces.h"

Piece::Piece(PieceType t, int s, int v) {
    type = t;
    square = s;
    value = v;
}

int Piece::getSquare() {
    return square;
}

int Piece::getValue() {
    return value;
}

PieceType Piece::getType() {
    return type;
}