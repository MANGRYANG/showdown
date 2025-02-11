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

std::vector<Vector2> Cannon::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos;
        int currentCol = selectedCoord.ypos;
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
                resultList.push_back(Vector2(currentRow, currentCol));
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

    if (((selectedCoord.xpos - selectedCoord.ypos) == -3 || selectedCoord.xpos + selectedCoord.ypos == 5) &&
        (selectedCoord.xpos != 1 || selectedCoord.ypos != 4) &&
        (board[1][4] != -1 && board[1][4] != 8)) {
        if (board[2 - selectedCoord.xpos][8 - selectedCoord.ypos] >= 7 && board[2 - selectedCoord.xpos][8 - selectedCoord.ypos] <= 13 &&
            board[2 - selectedCoord.xpos][8 - selectedCoord.ypos] != 8) {
            resultList.push_back(Vector2(2 - selectedCoord.xpos, 8 - selectedCoord.ypos));
        }
    }

    return resultList;
}

std::vector<Vector2> Cannon::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos;
        int currentCol = selectedCoord.ypos;
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
                    resultList.push_back(Vector2(currentRow, currentCol));
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

    if (((selectedCoord.xpos - selectedCoord.ypos) == -3 || selectedCoord.xpos + selectedCoord.ypos == 5) &&
        (selectedCoord.xpos != 1 || selectedCoord.ypos != 4) &&
        (board[1][4] != -1 && board[1][4] != 8)) {
        if (board[2 - selectedCoord.xpos][8 - selectedCoord.ypos] == -1) {
            resultList.push_back(Vector2(2 - selectedCoord.xpos, 8 - selectedCoord.ypos));
        }
    }

    return resultList;
}

