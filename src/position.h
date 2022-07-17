/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/
#include <vector>
#include <iostream>

#ifndef POSITION_H
#define POSITION_H

class Position {
    public:
        Position();
        Position(int b[8][8]);
        void reset();
        bool makeMove(std::string move);

    private:
        bool isValid(std::string move);
        int (*board)[8];
        static const int p = 1;
        static const int b = 3;
        static const int n = 3;
        static const int r = 5;
        static const int q = 9;
        static const int k = 6000;
};

#endif