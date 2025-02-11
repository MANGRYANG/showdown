#include "King.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

King::King(Vector2 location) : Super("K", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

King::~King()
{
}

std::vector<Vector2> King::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos + direction[0];
        int currentCol = selectedCoord.ypos + direction[1];

        if (currentRow >= 6 && currentRow <= 8 && currentCol >= 3 && currentCol <= 5) {
            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
        }
    }

    return resultList;
}

std::vector<Vector2> King::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos + direction[0];
        int currentCol = selectedCoord.ypos + direction[1];

        if (currentRow >= 6 && currentRow <= 8 && currentCol >= 3 && currentCol <= 5) {
            if (board[currentRow][currentCol] == -1) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
            else if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                continue;
            }
        }
    }

    return resultList;
}