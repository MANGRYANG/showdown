#include "Chariot.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Chariot::Chariot(Vector2 location) : Super("\u8ECA", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Chariot::~Chariot()
{
}

std::vector<Vector2> Chariot::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos, currentCol = selectedCoord.ypos;
        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];
            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) {
                break;
            }
            if (board[currentRow][currentCol] >= 0 && board[currentRow][currentCol] <= 6) {
                resultList.emplace_back(currentRow, currentCol);
                break;
            }
            else if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                break;
            }
        }
    }

    for (const auto& dir : innerDiagonalDirections) {
        int firstRow = selectedCoord.xpos + dir[0], firstCol = selectedCoord.ypos + dir[1];
        int secondRow = firstRow + dir[0], secondCol = firstCol + dir[1];

        if (firstRow >= 0 && firstRow <= 2 && firstCol >= 3 && firstCol <= 5) {
            if ((selectedCoord.xpos - selectedCoord.ypos) == -3 || selectedCoord.xpos + selectedCoord.ypos == 5) {
                if (board[firstRow][firstCol] >= 0 && board[firstRow][firstCol] <= 6) {
                    resultList.emplace_back(firstRow, firstCol);
                }
            }
        }

        if (secondRow >= 0 && secondRow <= 2 && secondCol >= 3 && secondCol <= 5) {
            if (((selectedCoord.xpos - selectedCoord.ypos) == -3 || selectedCoord.xpos + selectedCoord.ypos == 5) &&
                (selectedCoord.xpos != 1 || selectedCoord.ypos != 4)) {
                if (board[1][4] == -1 && board[secondRow][secondCol] >= 0 && board[secondRow][secondCol] <= 6) {
                    resultList.emplace_back(secondRow, secondCol);
                }
                else if (board[1][4] >= 0 && board[1][4] <= 6) {
                    resultList.emplace_back(1, 4);
                }
            }
        }
    }
    return resultList;
}

std::vector<Vector2> Chariot::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos, currentCol = selectedCoord.ypos;
        while (true) {
            currentRow += direction[0];
            currentCol += direction[1];
            if (currentRow < 0 || currentRow >= 9 || currentCol < 0 || currentCol >= 9) break;
            if (board[currentRow][currentCol] == -1) {
                resultList.emplace_back(currentRow, currentCol);
            }
            else {
                break;
            }
        }
    }

    for (const auto& dir : innerDiagonalDirections) {
        int firstRow = selectedCoord.xpos + dir[0], firstCol = selectedCoord.ypos + dir[1];
        int secondRow = firstRow + dir[0], secondCol = firstCol + dir[1];

        if (firstRow >= 0 && firstRow <= 2 && firstCol >= 3 && firstCol <= 5) {
            if ((selectedCoord.xpos - selectedCoord.ypos) == -3 || selectedCoord.xpos + selectedCoord.ypos == 5) {
                if (board[firstRow][firstCol] == -1) {
                    resultList.emplace_back(firstRow, firstCol);
                }
            }
        }

        if (secondRow >= 0 && secondRow <= 2 && secondCol >= 3 && secondCol <= 5) {
            if ((selectedCoord.xpos - selectedCoord.xpos) == -3 && board[1][4] == -1 && board[secondRow][secondCol] == -1) {
                resultList.emplace_back(secondRow, secondCol);
            }
        }
    }

    return resultList;
}

