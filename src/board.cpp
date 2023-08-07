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
    getFenBoard();
}

PheonixBoard::PheonixBoard(const PheonixBoard& other) : PheonixBoard(other.generateFEN())
{
}

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
    {
        currentMove = WHITE;
        citr++;
    }
    else
    {
        currentMove = BLACK;
        citr++;
    }

    castlingRights[WHITE] = {false, false};
    while (isupper(*citr))
    {
        if (*citr++ == 'K')
        {
            castlingRights[WHITE].first = true;
        }
        else
        {
            castlingRights[WHITE].second = true;
        }
    }

    castlingRights[BLACK] = {false, false};
    while (islower(*citr))
    {
        if (*citr++ == 'k')
        {
            castlingRights[BLACK].first = true;
        }
        else
        {
            castlingRights[BLACK].second = true;
        }
    }

    citr++;
    if (*citr++ != '-')
    {
        enPassantSquare.file = *citr++;
        enPassantSquare.rank = *citr++ - '0';
    }

    citr++;
    halfMoves = *citr++ - '0';

    citr++;
    fullMoves = *citr - '0';
}

Piece PheonixBoard::getPiece(int square) const
{
    uint64_t temp = 1;
    temp = temp << square;
    
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if ((temp & board[numPieceMap.at(i)]) != 0)
            return numPieceMap.at(i);
    }

    return EMPTY;
}

std::string PheonixBoard::generateFEN() const
{
    std::string fen = "";

    for (int i = 0; i < 8; ++i)
    {
        fen += getLine(i);

        if (i != 7)
            fen += '/';
    }

    if (currentMove == WHITE)
    {
        fen += " w ";
    }
    else
    {
        fen += " b ";
    }

    if (castlingRights[WHITE].first)
        fen += 'K';
    if (castlingRights[WHITE].second)
        fen += 'Q';
    if (castlingRights[BLACK].first)
        fen += 'k';
    if (castlingRights[BLACK].second)
        fen += 'q';

    

    return fen;
}

std::string PheonixBoard::getLine(int lineNum) const
{
    std::string line = "";

    uint64_t temp = 0x1;
    temp = temp << (8 * lineNum);
    int curStreak = 0;

    for (int i = 0; i < 8; ++i)
    {
        const Piece curPiece = getPiece(lineNum*8 + i);

        if (curPiece == EMPTY)
            curStreak++;
        else
        {
            if (curStreak != 0)
            {
                line += std::to_string(curStreak);
                curStreak = 0;
            }

            line += pieceLetterMap.at(curPiece);
        }
        temp = temp << 1;
    }

    if (curStreak != 0)
        line += std::to_string(curStreak);

    return line;
}

BitBoard PheonixBoard::getPieceBoard(Piece boardType) const
{
    return board[boardType];
}

std::string PheonixBoard::getFenBoard() const
{
    return generateFEN();
}

// bool PheonixBoard::isInCheck(Color player) const
// {
//     return false;
// }

bool PheonixBoard::isDraw() const
{
    return false;
}

// bool PheonixBoard::canCastle(Color player) const
// {
//     return false;
// }