/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#ifndef MOVEMANAGER_H
#define MOVEMANAGER_H

#include <board.h>
#include <mutex>

class MoveManager {
    public:
        MoveManager(MoveManager &) = delete;
        void operator=(const MoveManager &) = delete;
        
        static MoveManager *GetInstance();
        bool updateBoard(Move);

    protected:
        MoveManager() : board(PheonixBoard())
        {
        }
        ~MoveManager() = default;
        PheonixBoard board;

    private:
        static MoveManager* moveManager_;
        static std::mutex mutex_;
};

#endif