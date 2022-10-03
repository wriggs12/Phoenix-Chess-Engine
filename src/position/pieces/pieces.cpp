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
    else if (t == WHITE_PAWN) {
        validMoves = getValidWhitePawnMoves(b, square);
    }
    else {
        validMoves = getValidBlackPawnMoves(b, square);
    }

    return validMoves;
}

std::vector<int> Pieces::getValidWhitePawnMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    if (b.getPieceOnSquare(square + 8) == NO_PIECE) {
        moves.push_back(square + 8);
        if (square / 8 == 1 && b.getPieceOnSquare(square + 16) == NO_PIECE) {
            moves.push_back(square + 16);
        }
    }

    if ((square + 7) / 8 == (square / 8) + 1 && b.getPieceOnSquare(square + 7) != NO_PIECE && b.getPieceOnSquare(square + 7) != NOT_ON_BOARD) {
        moves.push_back(square + 7);
    }

    if ((square + 9) / 8 == (square / 8) + 1 && b.getPieceOnSquare(square + 9) != NO_PIECE && b.getPieceOnSquare(square + 9) != NOT_ON_BOARD) {
        moves.push_back(square + 9);
    }

    return moves;
}

std::vector<int> Pieces::getValidBlackPawnMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    if (b.getPieceOnSquare(square - 8) == NO_PIECE) {
        moves.push_back(square - 8);
        if (square / 8 == 6 && b.getPieceOnSquare(square - 16) == NO_PIECE) {
            moves.push_back(square - 16);
        }
    }

    if ((square - 7) / 8 == (square / 8) - 1 && b.getPieceOnSquare(square - 7) != NO_PIECE && b.getPieceOnSquare(square - 7) != NOT_ON_BOARD) {
        moves.push_back(square - 7);
    }

    if ((square - 9) / 8 == (square / 8) - 1 && b.getPieceOnSquare(square - 9) != NO_PIECE && b.getPieceOnSquare(square - 9) != NOT_ON_BOARD) {
        moves.push_back(square - 9);
    }

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
    Pieces p;
    PhoenixBoard b;

    std::vector<int> moves = p.getValidMoves(b.getPieceOnSquare(48), b, 48);

    for (int i = 0; i < moves.size(); i++) {
        std::cout << moves.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}