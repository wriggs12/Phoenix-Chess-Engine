#ifndef PIECES_H
#define PIECES_H

#include "../board/board.cpp"

#include <vector>

class Pieces {
    public:
        Pieces();
        std::vector<int> getValidMoves(PieceType t, PhoenixBoard b, int square);
        int getPieceValue(PieceType t);

    protected:

    private:
        std::vector<int> getValidWhitePawnMoves(PhoenixBoard b, int square);
        std::vector<int> getValidBlackPawnMoves(PhoenixBoard b, int square);
        std::vector<int> getValidKnightMoves(PhoenixBoard b, int square, PieceType t);
        std::vector<int> getValidBishopMoves(PhoenixBoard b, int square, PieceType t);
        std::vector<int> getValidRookMoves(PhoenixBoard b, int square, PieceType t); 
        std::vector<int> getValidQueenMoves(PhoenixBoard b, int square, PieceType t);
        std::vector<int> getValidKingMoves(PhoenixBoard b, int square, PieceType t);
        std::vector<int> getLineMoves(PhoenixBoard b, int square, PieceType t, std::vector<int> moves, int movement, int rankChange, int fileChange);
        bool isSameColor(PieceType t1, PieceType t2);
};

#endif