#include "pieces.h"

Pieces::Pieces() {

}

int Pieces::getPieceValue(PieceType t) {
    if (t == WHITE_ROOK || t == BLACK_ROOK) {
        return 5;
    }
    else if (t == WHITE_KNIGHT || t == BLACK_KNIGHT || t == WHITE_BISHOP || t == BLACK_BISHOP) {
        return 3;
    }
    else if (t == WHITE_QUEEN || t == BLACK_QUEEN) {
        return 9;
    }
    else if (t == WHITE_KING || t == BLACK_KING) {
        return 500;
    }
    else {
        return 1;
    }
}

std::vector<int> Pieces::getValidMoves(PieceType t, PhoenixBoard b, int square) {
    std::vector<int> validMoves;

    if (t == WHITE_ROOK || t == BLACK_ROOK) {
        validMoves = getValidRookMoves(b, square);
    }
    else if (t == WHITE_KNIGHT || t == BLACK_KNIGHT) {
        validMoves = getValidKnightMoves(b, square);
    }
    else if (t == WHITE_BISHOP || t == BLACK_BISHOP) {
        validMoves = getValidBishopMoves(b, square);
    }
    else if (t == WHITE_QUEEN || t == BLACK_QUEEN) {
        validMoves = getValidQueenMoves(b, square);
    }
    else if (t == WHITE_KING || t == BLACK_KING) {
        validMoves = getValidKingMoves(b, square);
    }
    else {
        validMoves = getValidPawnMoves(b, square);
    }

    return validMoves;
}

std::vector<int> Pieces::getValidPawnMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;
    
    return moves;
}

std::vector<int> Pieces::getValidKnightMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    return moves;
}

std::vector<int> Pieces::getValidBishopMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    return moves;
}

std::vector<int> Pieces::getValidRookMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    return moves;
}

std::vector<int> Pieces::getValidQueenMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    return moves;
}

std::vector<int> Pieces::getValidKingMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    return moves;
}

int main() {
    return 0;
}