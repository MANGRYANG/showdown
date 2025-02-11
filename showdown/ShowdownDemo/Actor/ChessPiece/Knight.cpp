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

std::vector<Vector2> Knight::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos + direction[0];
        int currentCol = selectedCoord.ypos + direction[1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedCoord.xpos + direction[0] / 2;
            int checkCol = selectedCoord.ypos + direction[1] / 2;

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] == 8) {
                    continue;
                }
            }

            if (board[currentRow][currentCol] >= 7 && board[currentRow][currentCol] <= 13) {
                resultList.push_back(Vector2(currentRow, currentCol));
            }
        }
    }

    return resultList;
}

std::vector<Vector2> Knight::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) {
    std::vector<Vector2> resultList;

    for (const auto& direction : directions) {
        int currentRow = selectedCoord.xpos + direction[0];
        int currentCol = selectedCoord.ypos + direction[1];

        if (currentRow >= 0 && currentRow < 9 && currentCol >= 0 && currentCol < 9) {
            int checkRow = selectedCoord.xpos + direction[0] / 2;
            int checkCol = selectedCoord.ypos + direction[1] / 2;

            if (checkRow >= 0 && checkRow < 9 && checkCol >= 0 && checkCol < 9) {
                if (board[checkRow][checkCol] == 8) {
                    continue;
                }
            }

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