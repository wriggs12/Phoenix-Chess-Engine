/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utils.h>

class PheonixBoard {
    public:
        PheonixBoard(const std::string& fen = DEFAULT_POSITION);
        PheonixBoard(const PheonixBoard& other);
        PheonixBoard& operator=(const PheonixBoard& other);
        std::ostream& operator<<(std::ostream& os);

        ~PheonixBoard() = default;

        BitBoard getPieceBoard(Piece boardType) const;
        std::string getFenBoard() const;

        bool isInCheck(Color player) const;
        bool isDraw() const;
        // void move(add move class/namespcae)
        bool canCastle(Color player) const;
        Piece getPiece(int square) const;

    private:
        void loadFEN(const std::string& fen);
        std::string generateFEN() const;
        std::string getLine(int lineNum) const;

    private:
        std::vector<BitBoard> board = std::vector<BitBoard>(BOARD_SIZE, 0);
        Color currentMove;
};

#endif
