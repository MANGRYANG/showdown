#include "Bishop.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Bishop::Bishop(Vector2 location) : Super("B", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Bishop::~Bishop()
{
}

std::vector<Vector2> Bishop::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos;
        int currentCol = selectedCoord.ypos;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(Vector2(currentRow, currentCol));
                break;
            }
            else if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                break;
            }
        }
    }

    return resultList;
}

std::vector<Vector2> Bishop::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos;
        int currentCol = selectedCoord.ypos;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] == -1) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
            else
            {
                break;
            }
        }
    }

    return resultList;
}
