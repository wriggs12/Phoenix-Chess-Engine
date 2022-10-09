#include "pieces.h"

Pieces::Pieces() {
    
} 

int Pieces::getPieceValue(PieceType t) {
    if (t == WHITE_ROOK || t == BLACK_ROOK)
        return 5;
    else if (t == WHITE_KNIGHT || t == BLACK_KNIGHT || t == WHITE_BISHOP || t == BLACK_BISHOP)
        return 3;
    else if (t == WHITE_QUEEN || t == BLACK_QUEEN)
        return 9;
    else if (t == WHITE_KING || t == BLACK_KING)
        return 500;
    else
        return 1;
}

std::vector<int> Pieces::getValidMoves(PieceType t, PhoenixBoard b, int square) {
    std::vector<int> validMoves;

    if (t == WHITE_ROOK || t == BLACK_ROOK)
        validMoves = getValidRookMoves(b, square, t);
    else if (t == WHITE_KNIGHT || t == BLACK_KNIGHT)
        validMoves = getValidKnightMoves(b, square, t);
    else if (t == WHITE_BISHOP || t == BLACK_BISHOP)
        validMoves = getValidBishopMoves(b, square, t);
    else if (t == WHITE_QUEEN || t == BLACK_QUEEN)
        validMoves = getValidQueenMoves(b, square, t);
    else if (t == WHITE_KING || t == BLACK_KING)
        validMoves = getValidKingMoves(b, square, t);
    else if (t == WHITE_PAWN)
        validMoves = getValidWhitePawnMoves(b, square);
    else
        validMoves = getValidBlackPawnMoves(b, square);

    return validMoves;
}

std::vector<int> Pieces::getValidWhitePawnMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    if (b.getPieceOnSquare(square + 8) == NO_PIECE) {
        moves.push_back(square + 8);
        if (square / 8 == 1 && b.getPieceOnSquare(square + 16) == NO_PIECE)
            moves.push_back(square + 16);
    }

    PieceType other = b.getPieceOnSquare(square + 7);
    if ((square + 7) / 8 == (square / 8) + 1 && other != NO_PIECE && other != NOT_ON_BOARD && !isSameColor(other, WHITE_PAWN))
        moves.push_back(square + 7);

    other = b.getPieceOnSquare(square + 9);
    if ((square + 9) / 8 == (square / 8) + 1 && other != NO_PIECE && other != NOT_ON_BOARD && !isSameColor(other, WHITE_PAWN))
        moves.push_back(square + 9);

    return moves;
}

std::vector<int> Pieces::getValidBlackPawnMoves(PhoenixBoard b, int square) {
    std::vector<int> moves;

    if (b.getPieceOnSquare(square - 8) == NO_PIECE) {
        moves.push_back(square - 8);
        if (square / 8 == 6 && b.getPieceOnSquare(square - 16) == NO_PIECE)
            moves.push_back(square - 16);
    }

    PieceType other = b.getPieceOnSquare(square - 7);
    if ((square - 7) / 8 == (square / 8) - 1 && other != NO_PIECE && other != NOT_ON_BOARD && !isSameColor(other, BLACK_PAWN))
        moves.push_back(square - 7);

    other = b.getPieceOnSquare(square - 9);
    if ((square - 9) / 8 == (square / 8) - 1 && other != NO_PIECE && other != NOT_ON_BOARD && !isSameColor(other, BLACK_PAWN))
        moves.push_back(square - 9);

    return moves;
}

std::vector<int> Pieces::getValidKnightMoves(PhoenixBoard b, int square, PieceType t) {
    std::vector<int> moves;

    int curRank = b.getRank(square);
    int curFile = b.getFile(square);

    //UP
    PieceType other = b.getPieceOnSquare(square + 17);
    int newRank = b.getRank(square + 17);
    int newFile = b.getFile(square + 17);

    if (other != NOT_ON_BOARD && curRank + 2 == newRank && curFile + 1 == newFile && !isSameColor(other, t))
        moves.push_back(square + 17);

    other = b.getPieceOnSquare(square + 15);
    newRank = b.getRank(square + 15);
    newFile = b.getFile(square + 15);

    if (other != NOT_ON_BOARD && curRank + 2 == newRank && curFile - 1 == newFile && !isSameColor(other, t))
        moves.push_back(square + 15);

    //RIGHT
    other = b.getPieceOnSquare(square + 10);
    newRank = b.getRank(square + 10);
    newFile = b.getFile(square + 10);

    if (other != NOT_ON_BOARD && curRank + 1 == newRank && curFile + 2 == newFile && !isSameColor(other, t))
        moves.push_back(square + 10);

    other = b.getPieceOnSquare(square - 6);
    newRank = b.getRank(square - 6);
    newFile = b.getFile(square - 6);

    if (other != NOT_ON_BOARD && curRank - 1 == newRank && curFile + 2 == newFile && !isSameColor(other, t))
        moves.push_back(square - 6);

    //DOWN
    other = b.getPieceOnSquare(square - 15);
    newRank = b.getRank(square - 15);
    newFile = b.getFile(square - 15);

    if (other != NOT_ON_BOARD && curRank - 2 == newRank && curFile + 1 == newFile && !isSameColor(other, t))
        moves.push_back(square - 15);

    other = b.getPieceOnSquare(square - 17);
    newRank = b.getRank(square - 17);
    newFile = b.getFile(square - 17);

    if (other != NOT_ON_BOARD && curRank - 2 == newRank && curFile - 1 == newFile && !isSameColor(other, t))
        moves.push_back(square - 17);

    //LEFT
    other = b.getPieceOnSquare(square - 10);
    newRank = b.getRank(square - 10);
    newFile = b.getFile(square - 10);

    if (other != NOT_ON_BOARD && curRank - 1 == newRank && curFile - 2 == newFile && !isSameColor(other, t))
        moves.push_back(square - 10);

    other = b.getPieceOnSquare(square + 6);
    newRank = b.getRank(square + 6);
    newFile = b.getFile(square + 6);

    if (other != NOT_ON_BOARD && curRank + 1 == newRank && curFile - 2 == newFile && !isSameColor(other, t))
        moves.push_back(square + 6);

    return moves;
}

//Use line movement method
std::vector<int> Pieces::getValidBishopMoves(PhoenixBoard b, int square, PieceType t) {
    std::vector<int> moves;

    //TOP-LEFT
    moves = getLineMoves(b, square,  t, moves, 7, 1, -1);

    //TOP-RIGHT
    moves = getLineMoves(b, square,  t, moves, 9, 1, 1);

    //BOTTOM-LEFT
    moves = getLineMoves(b, square,  t, moves, -9, -1, -1);

    //BOTTOM-RIGHT
    moves = getLineMoves(b, square,  t, moves, -7, -1, 1);

    return moves;
}

//Use line movement method
std::vector<int> Pieces::getValidRookMoves(PhoenixBoard b, int square, PieceType t) {
    std::vector<int> moves;

    //RIGHT
    moves = getLineMoves(b, square,  t, moves, 1, 0, 1);

    //DOWN
    moves = getLineMoves(b, square,  t, moves, -8, -1, 0);

    //LEFT
    moves = getLineMoves(b, square,  t, moves, -1, 0, -1);    

    //UP
    moves = getLineMoves(b, square,  t, moves, 8, 1, 0);

    return moves;
}

//Use line movement method
std::vector<int> Pieces::getValidQueenMoves(PhoenixBoard b, int square, PieceType t) {
    std::vector<int> moves;

    //RIGHT
    moves = getLineMoves(b, square,  t, moves, 1, 0, 1);

    //DOWN
    moves = getLineMoves(b, square,  t, moves, -8, -1, 0);

    //LEFT
    moves = getLineMoves(b, square,  t, moves, -1, 0, -1);    

    //UP
    moves = getLineMoves(b, square,  t, moves, 8, 1, 0);

    //TOP-LEFT
    moves = getLineMoves(b, square,  t, moves, 7, 1, -1);

    //TOP-RIGHT
    moves = getLineMoves(b, square,  t, moves, 9, 1, 1);

    //BOTTOM-LEFT
    moves = getLineMoves(b, square,  t, moves, -9, -1, -1);

    //BOTTOM-RIGHT
    moves = getLineMoves(b, square,  t, moves, -7, -1, 1);

    return moves;
}

std::vector<int> Pieces::getValidKingMoves(PhoenixBoard b, int square, PieceType t) {
    std::vector<int> moves;

    //Check moves for opposite color and iterate all moves for king
    //Also add some way to castle

    return moves;
}

std::vector<int> Pieces::getLineMoves(PhoenixBoard b, int square, PieceType t, std::vector<int> moves, int movement, int rankChange, int fileChange) {
    int curRank = b.getRank(square);
    int curFile = b.getFile(square);

    int newSquare = square + movement;

    PieceType other = b.getPieceOnSquare(newSquare);
    int newRank = b.getRank(newSquare);
    int newFile = b.getFile(newSquare);

    while (other != NOT_ON_BOARD && curRank + rankChange == newRank && curFile + fileChange == newFile && !isSameColor(other, t)) {
        moves.push_back(newSquare);

        if (other != NO_PIECE)
            break;

        curRank = newRank;
        curFile = newFile;
        newSquare = newSquare + movement;

        other = b.getPieceOnSquare(newSquare);

        newRank = b.getRank(newSquare);
        newFile = b.getFile(newSquare);
    }

    return moves;
}

bool Pieces::isSameColor(PieceType t1, PieceType t2) {
    if (t1 < 6 && t1 > -1 && t2 < 6 && t2 > -1)
        return true;
    
    if (t1 > 5 && t1 < 12 && t2 > 5 && t2 < 12)
        return true;

    return false;
}

int main() {
    Pieces p;
    PhoenixBoard b;

    b.updateBoard(12, 20);

    // for (int i = 7; i >= 0; i--) {
    //     for (int j = 0; j < 8; j++) {
    //         std::cout << b.getPieceOnSquare((i * 8) + j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<int> moves = p.getValidMoves(b.getPieceOnSquare(3), b, 3);

    for (int i = 0; i < moves.size(); i++)
        std::cout << moves.at(i) << " ";

    std::cout << std::endl;

    return 0;
}