#include "Guard.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Guard::Guard(Vector2 location) : Super("\u58EB", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Guard::~Guard()
{
}

std::vector<Vector2> Guard::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedCoord.xpos + directions[idx][0];
        int currentCol = selectedCoord.ypos + directions[idx][1];

        if (currentRow >= 0 && currentRow <= 2 && currentCol >= 3 && currentCol <= 5) {
            // Corner or Middle
            if ((selectedCoord.xpos + selectedCoord.ypos == 5) || (selectedCoord.xpos - selectedCoord.ypos) == -3) {
                if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                    resultList.push_back(Vector2(currentRow, currentCol));
                }
            }
            // Side
            else {
                if ((idx < 4) &&
                    board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                    resultList.push_back(Vector2(currentRow, currentCol));
                }
            }
        }
    }

    return resultList;
}

std::vector<Vector2> Guard::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedCoord.xpos + directions[idx][0];
        int currentCol = selectedCoord.ypos + directions[idx][1];

        if (currentRow >= 0 && currentRow <= 2 && currentCol >= 3 && currentCol <= 5) {
            // Corner or Middle
            if ((selectedCoord.xpos + selectedCoord.ypos == 5) || (selectedCoord.xpos - selectedCoord.ypos) == -3) {
                if (board[currentRow][currentCol] == -1) {
                    resultList.push_back(Vector2(currentRow, currentCol));
                }
                else if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                    continue;
                }
            }
            // Side
            else {
                if ((idx < 4) &&
                    board[currentRow][currentCol] == -1) {
                    resultList.push_back(Vector2(currentRow, currentCol));
                }
            }
        }
    }

    return resultList;
}
