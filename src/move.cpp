/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include "move.h"

Move::Move(std::string cr, std::string cc, std::string nr, std::string nc, std::string p) {
    this->curRow = cr;
    this->curCol = cc;
    this->newRow = nr;
    this->newCol = nc;
    this->piece = p;
}

std::string Move::getCurPos() {
    return this->curCol + this->curRow;
}

std::string Move::getNewPos() {
    return this->newCol + this->newRow;
}

std::string Move::getPiece() {
    return this->piece;
}

int Move::getColVal(std::string col) {
    std::string cols[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
    
    for (int i = 0; i < 8; i++) {
        if (col == cols[i]) {
            return i + 1;
        }
    }

    return -1;
}