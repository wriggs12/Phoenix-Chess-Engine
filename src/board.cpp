/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <iostream>
#include <board.h>

//TODO: Delete This
// void PheonixBoard::printBitBoard()
// {
//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             std::cout << board[0] 64 - ((i*8) + j)
//         }
//         std::cout << std::endl;
//     }
// }

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
}

BitBoard PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board[boardType];
}