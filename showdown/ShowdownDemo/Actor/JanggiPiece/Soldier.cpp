#include "Soldier.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Soldier::Soldier(Vector2 location) : Super("\u5175", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Soldier::~Soldier()
{
}

std::vector<std::pair<int, int>> Soldier::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	std::vector<std::pair<int, int>> resultList = {};

	if (isForward)
	{
		if (selectedRow <= 7 &&
			board[selectedRow + 1][selectedCol] >= 0 &&
			board[selectedRow + 1][selectedCol] <= 6)
		{
			resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol));
		}
	}

	else
	{
		if (selectedRow >= 1 &&
			board[selectedRow - 1][selectedCol] >= 0 &&
			board[selectedRow - 1][selectedCol] <= 6)
		{
			resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol));
		}
	}

	if (selectedCol >= 1 &&
		board[selectedRow][selectedCol - 1] >= 0 &&
		board[selectedRow][selectedCol - 1] <= 6)
	{
		resultList.push_back(std::pair<int, int>(selectedRow, selectedCol - 1));
	}

	if (selectedCol <= 7 &&
		board[selectedRow][selectedCol + 1] >= 0 &&
		board[selectedRow][selectedCol + 1] <= 6)
	{
		resultList.push_back(std::pair<int, int>(selectedRow, selectedCol + 1));
	}

	return resultList;
}

std::vector<std::pair<int, int>> Soldier::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	std::vector<std::pair<int, int>> resultList = {};

	if (isForward)
	{
		if (board[selectedRow + 1][selectedCol] == -1)
		{
			resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol));
		}
	}

	else
	{
		if (board[selectedRow - 1][selectedCol] == -1)
		{
			resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol));
		}
	}

	if (selectedCol > 1 && board[selectedRow][selectedCol - 1] == -1)
	{
		resultList.push_back(std::pair<int, int>(selectedRow, selectedCol - 1));
	}
	if (selectedCol < 8 && board[selectedRow][selectedCol + 1] == -1)
	{
		resultList.push_back(std::pair<int, int>(selectedRow, selectedCol + 1));
	}

	return resultList;
}

void Soldier::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}
