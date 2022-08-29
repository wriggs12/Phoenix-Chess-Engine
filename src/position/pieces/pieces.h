#ifndef PIECES_H
#define PIECES_H

#include "../../uils.h"
#include "../board/board.cpp"

#include <vector>

namespace Pieces {
    namespace {
        std::vector<int> getRookMoves(int sqaure, PhoenixBoard b) {

        }

        std::vector<int> getKnightMoves(int sqaure, PhoenixBoard b) {

        }

        std::vector<int> getBishopMoves(int sqaure, PhoenixBoard b) {

        }

        std::vector<int> getQueenMoves(int sqaure, PhoenixBoard b) {

        }

        std::vector<int> getKingMoves(int sqaure, PhoenixBoard b) {

        }

        std::vector<int> getPawnMoves(int sqaure, PhoenixBoard b) {

        }
    }

    int getValue(PieceType t) {
        if (t == 0) {
            return 5;
        }
        else if (t == 1) {
            return 3;
        }
        else if (t == 2) {
            return 3;
        }
        else if (t == 3) {
            return 9;
        }
        else if (t == 4) {
            return 40;
        }
        else if (t == 5) {
            return 1;
        }
        else {
            return 0;
        }
    }

    std::vector<int> getValidMoves(PieceType t, int square, PhoenixBoard b) {
        if (t == 6)
            return std::vector<int>();
        
        if (t == 0) {
            return getRookMoves(square, b);
        }
        else if (t == 1) {
            return getKingMoves(square, b);
        }
        else if (t == 2) {
            return getBishopMoves(square, b);
        }
        else if (t == 3) {
            return getQueenMoves(square, b);
        }
        else if (t == 4) {
            return getKingMoves(square, b);
        }
        else {
            return getPawnMoves(square, b);
        }
    }
}

#endif