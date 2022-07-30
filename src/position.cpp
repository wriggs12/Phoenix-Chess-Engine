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
    turn = 0;
}

Position::Position(int b[8][8]) {
    board = b;
    turn = 0;
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
    turn = 0;
}

bool Position::makeMove(Move move) {
    int rookMoves[4][2] = {{1, 0},
                            {-1, 0},
                            {0, 1},
                            {0, -1}};
    int knightMoves[8][2] = {{2, 1},
                              {2, -1},
                              {-2, 1},
                              {-2, -1},
                              {1, 2},
                              {-1, 2},
                              {1, -2},
                              {-1, -2}};
    int bishopMoves[4][2] = {{1, 1},
                              {1, -1},
                              {-1, 1},
                              {-1, -1}};
    int queenMoves[8][2] = {{1, 0},
                             {1, -1},
                             {0, -1},
                             {-1, -1},
                             {-1, 0},
                             {-1, 1},
                             {0, 1},
                             {1, 1}};
    int kingMoves[10][2] = {{1, 0},
                             {1, -1},
                             {0, -1},
                             {-1, -1},
                             {-1, 0},
                             {-1, 1},
                             {0, 1},
                             {1, 1},
                             {2, 0},
                             {-2, 0}};
    int pawnMoves[3][2] = {{1, 0},
                            {1, 1},
                            {1, -1}};

    if (!isValid(move)) {
        return false;
    }

    return true;
}

bool Position::isValid(Move move) {
    return true;
}

bool isValidKnightMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    int newColIndex = move.getColVal(newPos.substr(1, 1));
    int newRowIndex = std::stoi(newPos.substr(0, 1));

    std::cout << newRowIndex << std::endl;

    return true;
}

bool isValidRookMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    return true;
}

bool isValidBishopMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    return true;
}

bool isValidQueenMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    return true;
}

bool isValidKingMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    return true;
}

bool isValidPawnMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();
    return true;
}

int main() {
    Move test("a", "1", "c", "3", "n");
    isValidKnightMove(test);
    return 0;
}