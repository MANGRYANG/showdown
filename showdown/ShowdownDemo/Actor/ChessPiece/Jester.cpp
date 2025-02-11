#include "Jester.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Jester::Jester(Vector2 location) : Super("J", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Jester::~Jester()
{
}

std::vector<Vector2> Jester::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
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

std::vector<Vector2> Jester::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
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