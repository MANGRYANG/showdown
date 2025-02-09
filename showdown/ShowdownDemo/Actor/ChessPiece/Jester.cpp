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

std::vector<std::pair<int, int>> Jester::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow + direction[0];
        int currentCol = selectedCol + direction[1];

        if (currentRow >= 6 && currentRow <= 8 && currentCol >= 3 && currentCol <= 5) {
            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
            }
        }
    }

    return resultList;
}

std::vector<std::pair<int, int>> Jester::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow + direction[0];
        int currentCol = selectedCol + direction[1];

        if (currentRow >= 6 && currentRow <= 8 && currentCol >= 3 && currentCol <= 5) {
            if (board[currentRow][currentCol] == -1) {
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
            }
            else if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                continue;
            }
        }
    }

    return resultList;
}