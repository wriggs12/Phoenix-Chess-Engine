/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <iostream>
#include <board.h>

PheonixBoard::PheonixBoard(const std::string& fen)
{
    board = std::vector<BitBoard>(BOARD_SIZE, 0);
    loadFEN(fen);
}

PheonixBoard::PheonixBoard(const PheonixBoard& other) : PheonixBoard(other.getFenBoard())
{
}

PheonixBoard& PheonixBoard::operator=(const PheonixBoard& other)
{
    if (*this == other)
        return *this;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        const BitBoard& temp = other.board[i];
        board[i] = temp;
    }

    const FEN& otherFEN = other.boardFEN;

    this->boardFEN.fen = otherFEN.fen;
    this->boardFEN.currentMove = otherFEN.currentMove;
    this->boardFEN.enPassantSquare = otherFEN.enPassantSquare;
    this->boardFEN.halfMoves = otherFEN.halfMoves;
    this->boardFEN.fullMoves = otherFEN.fullMoves;

    this->boardFEN.castlingRights[WHITE] = otherFEN.castlingRights.at(WHITE);
    this->boardFEN.castlingRights[BLACK] = otherFEN.castlingRights.at(BLACK);

    return *this;
}

bool PheonixBoard::operator==(const PheonixBoard& other)
{
    return (other.getFenBoard() == this->getFenBoard());
}

// TODO: Make This Better, Reverse Top to bottom
std::ostream& operator<<(std::ostream& os, const PheonixBoard& other)
{
    std::unordered_map<int, std::string> tempMap = {
        {0,"White Pawn"},
        {1,"White Rook"},
        {2,"White Knight"},
        {3,"White Bishop"},
        {4,"White Queen"},
        {5,"White King"},
        {6,"Black Pawn"},
        {7,"Black Rook"},
        {8,"Black Knight"},
        {9,"Black Bishop"},
        {10,"Black Queen"},
        {11,"Black King"},
    };

    for (int k = 0; k < BOARD_SIZE; k++)
    {
        os << tempMap[k] << ": " << std::endl;
        uint64_t curSquare = 0x1;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                os << ((other.board[k] & curSquare) >> ((i*8) + j));
                curSquare = curSquare << 1;
            }
            os << std::endl;
        }
        os << std::endl;
    }

    return os;
}

void PheonixBoard::loadFEN(const std::string& fen)
{
    std::string::const_iterator citr = fen.begin();

    loadBoard(fen, citr);

    boardFEN.fen = fen;

    if (*citr++ == 'w')
    {
        boardFEN.currentMove = WHITE;
        citr++;
    }
    else
    {
        boardFEN.currentMove = BLACK;
        citr++;
    }

    boardFEN.castlingRights[WHITE] = {false, false};
    while (isupper(*citr))
    {
        if (*citr++ == 'K')
        {
            boardFEN.castlingRights[WHITE].first = true;
        }
        else
        {
            boardFEN.castlingRights[WHITE].second = true;
        }
    }

    boardFEN.castlingRights[BLACK] = {false, false};
    while (islower(*citr))
    {
        if (*citr++ == 'k')
        {
            boardFEN.castlingRights[BLACK].first = true;
        }
        else
        {
            boardFEN.castlingRights[BLACK].second = true;
        }
    }

    citr++;
    if (*citr++ != '-')
    {
        int file = *citr++ - 'a';
        int rank = *citr++ - '0';

        boardFEN.enPassantSquare = (file * 8) + rank;
    }

    citr++;
    boardFEN.halfMoves = *citr++ - '0';

    citr++;
    boardFEN.fullMoves = *citr - '0';
}

//TODO: Implement Move
bool PheonixBoard::move(Move& mv)
{
    BitBoard& pieceBoard = getPieceBoard(mv.piece);

    uint64_t mask = 0x1;

    mask = ~(mask << mv.start);
    pieceBoard = pieceBoard & mask;
    mask = 0x1 << mv.end;
    pieceBoard = pieceBoard | mask;

    Piece captured = getPiece(mv.end);
    if (captured != EMPTY)
    {
        
    }

    updateFEN();
    return true;
}

void PheonixBoard::updateFEN()
{
    if (boardFEN.currentMove == WHITE)
        boardFEN.currentMove = BLACK;
    else
        boardFEN.currentMove = WHITE;
}

void PheonixBoard::loadBoard(const std::string& fen, std::string::const_iterator& citr)
{
    uint64_t curSquare = 1;

    for (; citr != fen.end(); ++citr)
    {
        if (*citr == ' ')
        {
            ++citr;
            break;
        }
        else if (*citr == '/')
            continue;
        else if (isdigit(*citr))
            curSquare = curSquare << (*citr - '0');
        else
        {
            BitBoard& temp = board[pieceMap.at(*citr)];
            temp = temp | curSquare;
            curSquare = curSquare << 1;
        }
    }
}

Piece PheonixBoard::getPiece(Square s) const
{
    uint64_t square = 1;
    square = square << s;
    
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if ((square & board[numPieceMap.at(i)]) != 0)
            return numPieceMap.at(i);
    }

    return EMPTY;
}

BitBoard& PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board.at(boardType);
}

std::string PheonixBoard::getFenBoard() const
{
    return boardFEN.fen;
}

//TODO: Implement Logic
bool PheonixBoard::isInCheck(Color player) const
{
    return false;
}

bool PheonixBoard::isDraw() const
{
    return false;
}

std::pair<bool, bool> PheonixBoard::castle(Color player) const
{
    return boardFEN.castlingRights.at(player);
}

bool PheonixBoard::isOnBoard(Square s) const
{
    return (0 <= s && s < 64);
}

std::vector<Move>& PheonixBoard::getValidMoves(Piece& p)
{
    return validMoves;
}