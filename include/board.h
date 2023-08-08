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
        friend std::ostream& operator<<(std::ostream& os, const PheonixBoard& other);
        bool operator==(const PheonixBoard& other);

        ~PheonixBoard() = default;

        BitBoard getPieceBoard(Piece boardType) const;
        std::string getFenBoard() const;

        bool isInCheck(Color player) const;
        bool isDraw() const;
        bool move(Move mv);
        bool canCastle(Color player) const;
        Piece getPiece(int square) const;

    private:
        void loadFEN(const std::string& fen);
        void loadBoard(const std::string& fen, std::string::const_iterator& citr);
        void updateFEN();

    private:
        std::vector<BitBoard> board;
        FEN boardFEN;
};

#endif
