/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/
#include <vector>
#include <iostream>
#include "move.cpp"

#ifndef POSITION_H
#define POSITION_H

class Position {
    public:
        Position();
        Position(int b[8][8]);
        void reset();
        bool makeMove(Move move);

    private:
        bool isValid(Move move);
        bool isValidKnightMove(Move move);
        bool isValidRookMove(Move move);
        bool isValidBishopMove(Move move);
        bool isValidQueenMove(Move move);
        bool isValidKingMove(Move move);
        bool isValidPawnMove(Move move);
        bool standardChecks(std::string curPos, std::string newPos, Move move);
        int turn;
        int (*board)[8];
        static const int p = 1;
        static const int b = 3;
        static const int n = 3;
        static const int r = 5;
        static const int q = 9;
        static const int k = 6000;
};

#endif