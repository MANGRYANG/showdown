#include "Rook.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Rook::Rook(Vector2 location) : Super("R", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Rook::~Rook()
{
}

std::vector<std::pair<int, int>> Rook::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow;
        int currentCol = selectedCol;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                break;
            }
            else if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                break;
            }
        }
    }

    return resultList;
}

std::vector<std::pair<int, int>> Rook::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow;
        int currentCol = selectedCol;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] == -1) {
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
            }
            else
            {
                break;
            }
        }
    }

    return resultList;
}
