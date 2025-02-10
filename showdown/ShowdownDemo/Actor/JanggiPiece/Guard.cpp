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

std::vector<std::pair<int, int>> Guard::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedRow + directions[idx][0];
        int currentCol = selectedCol + directions[idx][1];

        if (currentRow >= 0 && currentRow <= 2 && currentCol >= 3 && currentCol <= 5) {
            // Corner or Middle
            if ((selectedRow + selectedCol == 5) || (selectedRow - selectedCol) == -3) {
                if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                    resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                }
            }
            // Side
            else {
                if ((idx < 4) &&
                    board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                    resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                }
            }
        }
    }

    return resultList;
}

std::vector<std::pair<int, int>> Guard::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedRow + directions[idx][0];
        int currentCol = selectedCol + directions[idx][1];

        if (currentRow >= 0 && currentRow <= 2 && currentCol >= 3 && currentCol <= 5) {
            // Corner or Middle
            if ((selectedRow + selectedCol == 5) || (selectedRow - selectedCol) == -3) {
                if (board[currentRow][currentCol] == -1) {
                    resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                }
                else if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                    continue;
                }
            }
            // Side
            else {
                if ((idx < 4) &&
                    board[currentRow][currentCol] == -1) {
                    resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                }
            }
        }
    }

    return resultList;
}
