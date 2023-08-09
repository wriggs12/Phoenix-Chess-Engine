/****************************************************************************
 *  Author:  Winston Riggs
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2023, Winston Riggs <wriggs12@gmail.com>
 ****************************************************************************/

#include <moveManager.h>

MoveManager* MoveManager::GetInstance()
{
    if (moveManager_ == nullptr)
    {
        moveManager_ = new MoveManager();
    }

    return moveManager_;
}

bool MoveManager::updateBoard(Move mv)
{
}
