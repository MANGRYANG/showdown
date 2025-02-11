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

std::vector<Vector2> Pawn::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	std::vector<Vector2> resultList = {};

	if (isForward)
	{
		if (selectedCoord.ypos == 0)
		{
			if (board[selectedCoord.xpos - 1][selectedCoord.ypos + 1] >= 7 &&
				board[selectedCoord.xpos - 1][selectedCoord.ypos + 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos + 1));
			}
		}
		else if (selectedCoord.ypos == 8)
		{
			if (board[selectedCoord.xpos - 1][selectedCoord.ypos - 1] >= 7 &&
				board[selectedCoord.xpos - 1][selectedCoord.ypos - 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos - 1));
			}
		}
		else
		{
			if (board[selectedCoord.xpos - 1][selectedCoord.ypos + 1] >= 7 &&
				board[selectedCoord.xpos - 1][selectedCoord.ypos + 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos + 1));
			}

			if (board[selectedCoord.xpos - 1][selectedCoord.ypos - 1] >= 7 &&
				board[selectedCoord.xpos - 1][selectedCoord.ypos - 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos - 1));
			}
		}
		
	}

	else
	{
		if (selectedCoord.ypos == 0)
		{
			if (board[selectedCoord.xpos + 1][selectedCoord.ypos + 1] >= 7 &&
				board[selectedCoord.xpos + 1][selectedCoord.ypos + 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos + 1));
			}
		}
		else if (selectedCoord.ypos == 8)
		{
			if (board[selectedCoord.xpos + 1][selectedCoord.ypos - 1] >= 7 &&
				board[selectedCoord.xpos + 1][selectedCoord.ypos - 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos - 1));
			}
		}
		else
		{
			if (board[selectedCoord.xpos + 1][selectedCoord.ypos + 1] >= 7 &&
				board[selectedCoord.xpos + 1][selectedCoord.ypos + 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos + 1));
			}

			if (board[selectedCoord.xpos + 1][selectedCoord.ypos - 1] >= 7 &&
				board[selectedCoord.xpos + 1][selectedCoord.ypos - 1] <= 13)
			{
				resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos - 1));
			}
		}

	}

	return resultList;
}

std::vector<Vector2> Pawn::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	std::vector<Vector2> resultList = {};

	if (isForward)
	{
		if (board[selectedCoord.xpos - 1][selectedCoord.ypos] == -1)
		{
			resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos));

			if (selectedCoord.xpos == 7 && board[selectedCoord.xpos - 2][selectedCoord.ypos] == -1)
			{
				resultList.push_back(Vector2(selectedCoord.xpos - 2, selectedCoord.ypos));
			}
		}
	}
	
	else
	{
		if (board[selectedCoord.xpos + 1][selectedCoord.ypos] == -1)
		{
			resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos));

			if (selectedCoord.xpos == 1 && board[selectedCoord.xpos + 2][selectedCoord.ypos] == -1)
			{
				resultList.push_back(Vector2(selectedCoord.xpos + 2, selectedCoord.ypos));
			}
		}
	}
	
	return resultList;
}

void Pawn::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}
