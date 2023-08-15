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
        PheonixBoard(const PheonixBoard &);

        PheonixBoard& operator=(const PheonixBoard &);
        friend std::ostream& operator<<(std::ostream &, const PheonixBoard &);
        bool operator==(const PheonixBoard &);

        ~PheonixBoard() = default;

        BitBoard getPieceBoard(Piece) const;
        std::string getFenBoard() const;

        bool move(Move &);

        bool isInCheck(Color) const;
        bool isDraw() const;
        bool isOnBoard(Square) const;
        std::pair<bool, bool> castle(Color) const;
        static std::vector<Move>& getValidMoves(Piece &);
        Piece getPiece(Square) const;

    public:
        static inline std::vector<Move> validMoves;

    private:
        void loadFEN(const std::string &);
        void loadBoard(const std::string &, std::string::const_iterator &);
        void updateFEN();

    private:
        std::vector<BitBoard> board;
        FEN boardFEN;
};

#endif
