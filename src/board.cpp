/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <iostream>
#include <board.h>

// TODO: Delete This
void PheonixBoard::printBitBoard()
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
        std::cout << tempMap[k] << ": " << std::endl;
        uint64_t curSquare = 0x1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                std::cout << ((board[k] & curSquare) >> ((i*8) + j));
                curSquare = curSquare << 1;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void PheonixBoard::loadFEN(const std::string& fen)
{
    uint64_t curSquare = 1;
    std::string::const_iterator citr = fen.begin();

    for (; citr != fen.end(); ++citr)
    {
        if (*citr == ' ')
            break;
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

PheonixBoard::PheonixBoard(const std::string& fen)
{
    loadFEN(fen);
    printBitBoard();
}

BitBoard PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board[boardType];
}