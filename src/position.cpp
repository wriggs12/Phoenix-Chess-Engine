/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/
#include "position.h"

Position::Position() {
    int temp[8][8] = {{r, n, b, q, k, b, n, r},
                    {p, p, p, p, p, p, p, p},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {p, p, p, p, p, p, p, p},
                    {r, n, b, q, k, b, n, r}};
    board = temp;
}

Position::Position(int b[8][8]) {
    board = b;
}

void Position::reset() {
    int temp[8][8] = {{r, n, b, q, k, b, n, r},
                    {p, p, p, p, p, p, p, p},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {p, p, p, p, p, p, p, p},
                    {r, n, b, q, k, b, n, r}};
    board = temp;
}

bool Position::makeMove(std::string move) {
    if (!isValid(move)) {
        return false;
    }

    return true;
}

bool Position::isValid(std::string move) {
    return true;
}