#include "Pawn.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Pawn::Pawn(Vector2 location) : Super("P", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Pawn::~Pawn()
{
}

std::vector<std::pair<int, int>> Pawn::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	std::vector<std::pair<int, int>> resultList = {};

	// Chess side
	if (isForward)
	{
		if (selectedCol == 0)
		{
			if (board[selectedRow - 1][selectedCol + 1] >= 7 &&
				board[selectedRow - 1][selectedCol + 1] <= 13)
			{
				resultList.push_back(std::pair<int, int> (selectedRow - 1, selectedCol + 1));
			}
		}
		else if (selectedCol == 8)
		{
			if (board[selectedRow - 1][selectedCol - 1] >= 7 &&
				board[selectedRow - 1][selectedCol - 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol - 1));
			}
		}
		else
		{
			if (board[selectedRow - 1][selectedCol + 1] >= 7 &&
				board[selectedRow - 1][selectedCol + 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol + 1));
			}

			if (board[selectedRow - 1][selectedCol - 1] >= 7 &&
				board[selectedRow - 1][selectedCol - 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol - 1));
			}
		}
		
	}

	// Janggi side
	else
	{
		if (selectedCol == 0)
		{
			if (board[selectedRow + 1][selectedCol + 1] >= 7 &&
				board[selectedRow + 1][selectedCol + 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol + 1));
			}
		}
		else if (selectedCol == 8)
		{
			if (board[selectedRow + 1][selectedCol - 1] >= 7 &&
				board[selectedRow + 1][selectedCol - 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol - 1));
			}
		}
		else
		{
			if (board[selectedRow + 1][selectedCol + 1] >= 7 &&
				board[selectedRow + 1][selectedCol + 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol + 1));
			}

			if (board[selectedRow + 1][selectedCol - 1] >= 7 &&
				board[selectedRow + 1][selectedCol - 1] <= 13)
			{
				resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol - 1));
			}
		}

	}

	return resultList;
}

std::vector<std::pair<int, int>> Pawn::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	std::vector<std::pair<int, int>> resultList = {};

	if (isForward)
	{
		if (board[selectedRow - 1][selectedCol] == -1)
		{
			resultList.push_back(std::pair<int, int>(selectedRow - 1, selectedCol));

			if (selectedRow == 7 && board[selectedRow - 2][selectedCol] == -1)
			{
				resultList.push_back(std::pair<int, int>(selectedRow - 2, selectedCol));
			}
		}
	}
	
	else
	{
		if (board[selectedRow + 1][selectedCol] == -1)
		{
			resultList.push_back(std::pair<int, int>(selectedRow + 1, selectedCol));

			if (selectedRow == 1 && board[selectedRow + 2][selectedCol] == -1)
			{
				resultList.push_back(std::pair<int, int>(selectedRow + 2, selectedCol));
			}
		}
	}
	
	return resultList;
}

void Pawn::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}
