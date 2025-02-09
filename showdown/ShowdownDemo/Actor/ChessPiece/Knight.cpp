#include "Knight.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Knight::Knight(Vector2 location) : Super("N", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Knight::~Knight()
{
}

std::vector<std::pair<int, int>> Knight::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow + direction[0];
        int currentCol = selectedCol + direction[1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedRow + direction[0] / 2;
            int checkCol = selectedCol + direction[1] / 2;

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] == 8) {
                    continue;
                }
            }

            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
            }
        }
    }

    return resultList;
}

std::vector<std::pair<int, int>> Knight::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) {
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow + direction[0];
        int currentCol = selectedCol + direction[1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedRow + direction[0] / 2;
            int checkCol = selectedCol + direction[1] / 2;

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] == 8) {
                    continue;
                }
            }

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