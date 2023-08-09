/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef MOVEMANAGER_H
#define MOVEMANAGER_H

#include <board.h>

class MoveManager {
    public:
        MoveManager(MoveManager &) = delete;
        void operator=(const MoveManager &) = delete;
        
        static MoveManager *GetInstance();
        bool updateBoard(Move);

    private:
        MoveManager() : board(PheonixBoard())
        {
        }

        static MoveManager* moveManager_;
        PheonixBoard board;
};

#endif