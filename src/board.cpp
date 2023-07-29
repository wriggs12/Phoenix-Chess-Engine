/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <iostream>
#include <board.h>

PheonixBoard::PheonixBoard(const std::string& fen)
{
    loadFEN(fen);
}

// PheonixBoard::PheonixBoard(const PheonixBoard& other)
// {
    
// }

// PheonixBoard& PheonixBoard::opeartor=(const PheonixBoard& other)
// {

// }

// TODO: Make This Better, Reverse Top to bottom
std::ostream& PheonixBoard::operator<<(std::ostream& os)
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

    for (int k = 0; k < 12; k++)
    {
        os << tempMap[k] << ": " << std::endl;
        uint64_t curSquare = 0x1;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                os << ((board[k] & curSquare) >> ((i*8) + j));
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
    uint64_t curSquare = 1;
    std::string::const_iterator citr = fen.begin();

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

    if (*citr++ == 'w')
        currentMove = WHITE;
    else
        currentMove = BLACK;
}

Piece PheonixBoard::getPiece(int square) const
{
    uint64_t temp = 0x1 << (square - 1);
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if ((temp & board[i]) != 0)
            return numPieceMap.at(i);
    }

    return EMPTY;
}

std::string PheonixBoard::generateFEN() const
{
    std::string fen = "";



    return fen;
}

BitBoard PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board[boardType];
}

std::string PheonixBoard::getFenBoard() const
{
    return generateFEN();
}

bool PheonixBoard::isInCheck(Color player) const
{
    return false;
}

bool PheonixBoard::isDraw() const
{
    return false;
}

bool PheonixBoard::canCastle(Color player) const
{
    return false;
}