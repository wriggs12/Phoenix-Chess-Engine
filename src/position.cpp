/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2022, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/
#include "position.h"

namespace utils {
    class Piece {
        public:
            Piece() {
                val = 1;
                color = "white";
            }
            Piece(std::string c) {
                val = 1;
                color = c;
            }
            Piece(std::string c, int v) {
                val = v;
                color = c;
            }
            std::string getColor() {
                return color;
            }
            int getVal() {
                return val;
            }
        
        private:
            std::string color;
            int val;
    };

    class Square {
        public:
            Square() {
                row = 1;
                col = 'a';
            }
            Square(int r, char c) {
                row = r;
                col = c;
            }
            Square(Piece p) {
                piece = p;
                row = 1;
                col = 'a';
            }
            Square(Piece p, int r, char c) {
                piece = p;
                row = r;
                col = c;
            }
            bool isOccupied() {
                if (piece == NULL)
                    return true;
                return false;
            }

        private:
            Piece piece;
            int row;
            char col;
    }
}

Position::Position() {
    setup();
}

Position::Position(int b[8][8]) {
    board = b;
    turn = 0;
}

void Position::reset() {
    setup();
}

void Position::setup() {
    utils::Piece whitePawn("white", 1);
    utils::Piece whiteRook("white", 5);
    utils::Piece whiteKnight("white", 3);
    utils::Piece whiteBishop("white", 3);
    utils::Piece whiteQueen("white", 9);
    utils::Piece whiteKing("white", 6000);

    utils::Piece blackPawn("black", 1);
    utils::Piece blackRook("black", 5);
    utils::Piece blackKnight("black", 3);
    utils::Piece blackBishop("black", 3);
    utils::Piece blackQueen("black", 9);
    utils::Piece blackKing("black", 6000);

    utils::Square empty();

    utils::Square temp[8][8]; {{utils::Square(blackRook, 8, 'a')},
                                {},
                                {},
                                {},
                                {},
                                {},
                                {},
                                {}};

    int temp[8][8] = {{blackRook.getVal(), blackKnight.getVal(), blackBishop.getVal(), blackQueen.getVal(), blackKing.getVal(), blackBishop.getVal(), blackKnight.getVal(), blackRook.getVal()},
                    {blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal(), blackPawn.getVal()},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal(), whitePawn.getVal()},
                    {whiteRook.getVal(), whiteKnight.getVal(), whiteBishop.getVal(), whiteQueen.getVal(), whiteKing.getVal(), whiteBishop.getVal(), whiteKnight.getVal(), whiteRook.getVal()}};
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
    std::string piece = move.getPiece();

    if (piece == "r") {
        if (!isValidRookMove(move))
            return false;
    }
    else if (piece == "n") {
        if (!isValidKnightMove(move))
            return false;
    }
    else if (piece == "b") {
        if (!isValidBishopMove(move))
            return false;
    }  
    else if (piece == "q") {
        if (!isValidQueenMove(move))
            return false;
    }
    else if (piece == "k") {
        if (!isValidKingMove(move))
            return false;
    }
    else if (piece == "p") {
        if (!isValidPawnMove(move))
            return false;
    }
    else
        return false;

    return true;
}

bool Position::isValidKnightMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidRookMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if (rowDiff != 0 && colDiff != 0)
        return false;

    return true;
}

bool Position::isValidBishopMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if (rowDiff - colDiff != 0)
        return false;

    return true;
}

bool Position::isValidQueenMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if (rowDiff - colDiff != 0)
        return false;

    return true;
}

bool Position::isValidKingMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if ((rowDiff == 2 && colDiff != 1) || (rowDiff == 1 && colDiff != 2))
        return false;

    return true;
}

bool Position::isValidPawnMove(Move move) {
    if (!standardChecks(move))
        return false;

    int colDiff = getColDiff(move);
    int rowDiff = getRowDiff(move);

    if ((rowDiff != 1 && rowDiff != 2) || (rowDiff == 1 && colDiff != 0))
        return false;

    return true;
}

bool Position::standardChecks(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

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

int Position::getColDiff(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curCol = move.getColVal(curPos.substr(1, 1));
    int newCol = move.getColVal(newPos.substr(1, 1));

    return std::abs(curCol - newCol);
}

int Position::getRowDiff(Move move) {
    std::string curPos = move.getCurPos();
    std::string newPos = move.getNewPos();

    int curRow = std::stoi(curPos.substr(0, 1));
    int newRow = std::stoi(curPos.substr(0, 1));

    return std::abs(curRow - newRow);
}