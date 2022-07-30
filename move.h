/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <iostream>

#ifndef MOVE_H
#define MOVE_H

class Move {
    public:
        Move(std::string cr, std::string cc, std::string nr, std::string nc, std::string p);
        std::string getCurPos();
        std::string getNewPos();
        std::string getPiece();
        int getColVal(std::string col);
    private:
        std::string curRow;
        std::string curCol;
        std::string newRow;
        std::string newCol;
        std::string piece;
};

#endif