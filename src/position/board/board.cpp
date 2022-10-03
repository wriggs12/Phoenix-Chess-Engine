#include "board.h"
#include <iostream>

PhoenixBoard::PhoenixBoard() {
    std::vector<PieceType> whiteStart = {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK};
    std::vector<PieceType> blackStart = {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK};
    std::vector<PieceType> whitePawns = {WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN};
    std::vector<PieceType> blackPawns = {BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN};
    std::vector<PieceType> empty;

    for (int i = 0; i < 8; i++) {
        empty.push_back(NO_PIECE);
    }

    board.push_back(whiteStart);
    board.push_back(whitePawns);

    for (int i = 0; i < 4; i++) {
        board.push_back(empty);
    }

    board.push_back(blackPawns);
    board.push_back(blackStart);

    whiteKingMoved = false;
    blackKingMoved = false;
}

PieceType PhoenixBoard::getPieceOnSquare(int square) {
    int rank = square / 8;
    int file = square % 8;

    return board[rank][file];
}

void PhoenixBoard::updateBoard(int startSquare, int endSquare) {
    int startRank = startSquare / 8;
    int endRank = endSquare / 8;

    int startFile = startSquare % 8;
    int endFile = endSquare % 8;

    board[endRank][endFile] = board[startRank][startFile];
    board[startRank][startFile] = NO_PIECE;
}

bool PhoenixBoard::hasWhiteKingMoved() {
    return whiteKingMoved;
}

bool PhoenixBoard::hasBlackKingMoved() {
    return blackKingMoved;
}