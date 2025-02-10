#include "Cannon.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Cannon::Cannon(Vector2 location) : Super("\u5305", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Cannon::~Cannon()
{
}

std::vector<std::pair<int, int>> Cannon::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow;
        int currentCol = selectedCol;
        bool isJumped = false;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                if (!isJumped) {
                    isJumped = true;
                    continue;
                }
                resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                break;
            }
            else if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                if (board[currentRow][currentCol] == 8) {
                    break;
                }
                if (!isJumped) {
                    isJumped = true;
                    continue;
                }
                break;
            }
        }
    }

    if (((selectedRow - selectedCol) == -3 || selectedRow + selectedCol == 5) &&
        (selectedRow != 1 || selectedCol != 4) &&
        (board[1][4] != -1 && board[1][4] != 8)) {
        if (board[2 - selectedRow][8 - selectedCol] >= 7 && board[2 - selectedRow][8 - selectedCol] <= 13 &&
            board[2 - selectedRow][8 - selectedCol] != 8) {
            resultList.push_back(std::pair<int, int>(2 - selectedRow, 8 - selectedCol));
        }
    }

    return resultList;
}

std::vector<std::pair<int, int>> Cannon::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
    std::vector<std::pair<int, int>> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedRow;
        int currentCol = selectedCol;
        bool isJumped = false;

        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];

            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }

            if (board[currentRow][currentCol] == -1) {
                if (!isJumped) {
                    continue;
                }
                else {
                    resultList.push_back(std::pair<int, int>(currentRow, currentCol));
                }
            }

            else if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 13) {
                if (board[currentRow][currentCol] == 8) {
                    break;
                }
                if (!isJumped) {
                    isJumped = true;
                    continue;
                }
                break;
            }
        }
    }

    if (((selectedRow - selectedCol) == -3 || selectedRow + selectedCol == 5) &&
        (selectedRow != 1 || selectedCol != 4) &&
        (board[1][4] != -1 && board[1][4] != 8)) {
        if (board[2 - selectedRow][8 - selectedCol] == -1) {
            resultList.push_back(std::pair<int, int>(2 - selectedRow, 8 - selectedCol));
        }
    }

    return resultList;
}

