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

bool Position::isValidKnightMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidRookMove(Move move) {
std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidBishopMove(Move move) {
std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidQueenMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidKingMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidPawnMove(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (!standardChecks(curPos, newPos, move))
        return false;

    int rowDiff = std::abs(curCol - newCol);
    int colDiff = std::abs(curRow - newRow);

    if ((rowDiff == 1 && colDiff != 1) || (rowDiff == 1 && colDiff != 0))
        return false;

    return true;
}

bool Position::standardChecks(std::string curPos, std::string newPos, Move move) {
    int curCol = move.getColVal(curPos.substr(1, 1));
    int curRow = std::stoi(curPos.substr(0, 1));

    int newCol = move.getColVal(newPos.substr(1, 1));
    int newRow = std::stoi(newPos.substr(0, 1));

    if (newCol < 1 || newCol > 8)
        return false;
    
    if (newRow < 1 || newRow > 8)
        return false;

    int newColIndex = newCol - 1;
    int newRowIndex = newRow - 1;

    if (board[newRowIndex][newColIndex] != 0)
        return false;

    return true;
}