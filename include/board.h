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
        PheonixBoard(const std::string & = DEFAULT_POSITION);
        PheonixBoard(PheonixBoard &);
        ~PheonixBoard() = default;

        PheonixBoard& operator=(const PheonixBoard &);
        bool operator==(const PheonixBoard &);

        bool move(Move &);
        BitBoard getPieceBoard(Piece) const;
        std::string getFenBoard() const;
        bool isInCheck(Color) const;
        bool isDraw() const;
        bool isOnBoard(Square) const;
        std::pair<bool, bool> castle(Color) const;
        Piece getPiece(Square) const;

    private:
        void loadFEN(const std::string &);
        void loadBoard(const std::string &, std::string::const_iterator &);
        void updateFEN(Move &);
        void updateValidMoves();
        std::vector<Move> getValidMoves(Piece &) const;

    private:
        std::vector<BitBoard> board;
        FEN boardFEN;
        std::unordered_map<Piece, std::vector<Move>> validMoves;
};

std::ostream& operator<<(std::ostream &, const PheonixBoard &);

#endif
