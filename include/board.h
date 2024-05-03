/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utils.h>

class PhoenixBoard {
    public:
        PhoenixBoard(const std::string&& = DEFAULT_POSITION);
        PhoenixBoard(const PhoenixBoard&);
        ~PhoenixBoard() = default;
        PhoenixBoard& operator=(const PhoenixBoard&);

        bool move(Move&);
        const BitBoard& getPieceBoard(Piece&) const;
        FEN getFenBoard() const;
        Piece getPiece(Square&) const;

        bool isInCheck(Color&) const;
        bool isDraw() const;
        bool isOnBoard(Square&) const;

        const std::pair<bool, bool>& castle(Color&) const;

    private:
        void loadFEN(const std::string&);
        void loadBoard(const std::string&, std::string::const_iterator&);

        void updateFEN(Move&, Piece&);
        void updateValidMoves();

        const std::vector<Move>& getValidMoves(Piece&) const;

        void log_board(BitBoard&);

    private:
        std::vector<BitBoard> board;
        FEN boardFEN;
        std::unordered_map<Piece, std::vector<Move>> validMoves;
};

std::ostream& operator<<(std::ostream&, const PhoenixBoard&);

#endif
