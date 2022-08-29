#include "board.h"

PhoenixBoard::PhoenixBoard() {
    std::vector<PieceType> whiteStart = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    std::vector<PieceType> blackStart = {ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};
    std::vector<PieceType> pawns;
    std::vector<PieceType> empty;

    for (int i = 0; i < 8; i++) {
        pawns.push_back(PAWN);
        empty.push_back(NO_PIECE);
    }

    board.push_back(blackStart);
    board.push_back(pawns);

    for (int i = 0; i < 4; i++) {
        board.push_back(empty);
    }

    board.push_back(pawns);
    board.push_back(whiteStart);
}

PieceType PhoenixBoard::getPieceOnSquare(int square) {
    int rank = square / 8;
    int file = square % 8;

    return board[rank][file];
}

bool PhoenixBoard::updateBoard(int startSquare, int endSquare) {
    int startRank = startSquare / 8;
    int endRank = endSquare / 8;

    int startFile = startSquare % 8;
    int endFile = endSquare % 8;

    board[endRank][endFile] = board[startRank][startFile];
    board[startRank][startFile] = NO_PIECE;
}