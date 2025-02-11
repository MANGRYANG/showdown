#include "Horse.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Horse::Horse(Vector2 location) : Super("\u99AC", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Horse::~Horse()
{
}

std::vector<Vector2> Horse::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedCoord.xpos + directions[idx][0];
        int currentCol = selectedCoord.ypos + directions[idx][1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedCoord.xpos + checkDirections[idx / 2][0];
            int checkCol = selectedCoord.ypos + checkDirections[idx / 2][1];

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] != -1) {
                    continue;
                }
            }

            if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
        }
    }

    return resultList;
}

std::vector<Vector2> Horse::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (int idx = 0; idx < 8; ++idx) {
        int currentRow = selectedCoord.xpos + directions[idx][0];
        int currentCol = selectedCoord.ypos + directions[idx][1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedCoord.xpos + checkDirections[idx / 2][0];
            int checkCol = selectedCoord.ypos + checkDirections[idx / 2][1];

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] != -1) {
                    continue;
                }
            }

            if (board[currentRow][currentCol] == -1) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
            else if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                continue;
            }
        }
    }

    return resultList;
}
