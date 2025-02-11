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

std::vector<Vector2> Soldier::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	std::vector<Vector2> resultList = {};

	if (isForward)
	{
		if (selectedCoord.xpos <= 7 &&
			board[selectedCoord.xpos + 1][selectedCoord.ypos] >= 0 &&
			board[selectedCoord.xpos + 1][selectedCoord.ypos] <= 6)
		{
			resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos));
		}
	}

	else
	{
		if (selectedCoord.xpos >= 1 &&
			board[selectedCoord.xpos - 1][selectedCoord.ypos] >= 0 &&
			board[selectedCoord.xpos - 1][selectedCoord.ypos] <= 6)
		{
			resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos));
		}
	}

	if (selectedCoord.ypos >= 1 &&
		board[selectedCoord.xpos][selectedCoord.ypos - 1] >= 0 &&
		board[selectedCoord.xpos][selectedCoord.ypos - 1] <= 6)
	{
		resultList.push_back(Vector2(selectedCoord.xpos, selectedCoord.ypos - 1));
	}

	if (selectedCoord.ypos <= 7 &&
		board[selectedCoord.xpos][selectedCoord.ypos + 1] >= 0 &&
		board[selectedCoord.xpos][selectedCoord.ypos + 1] <= 6)
	{
		resultList.push_back(Vector2(selectedCoord.xpos, selectedCoord.xpos + 1));
	}

	return resultList;
}

std::vector<Vector2> Soldier::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	std::vector<Vector2> resultList = {};

	if (isForward)
	{
		if (selectedCoord.xpos < 8 && board[selectedCoord.xpos + 1][selectedCoord.ypos] == -1)
		{
			resultList.push_back(Vector2(selectedCoord.xpos + 1, selectedCoord.ypos));
		}
	}

	else
	{
		if (selectedCoord.xpos > 0 && board[selectedCoord.xpos - 1][selectedCoord.ypos] == -1)
		{
			resultList.push_back(Vector2(selectedCoord.xpos - 1, selectedCoord.ypos));
		}
	}

	if (selectedCoord.ypos > 1 && board[selectedCoord.xpos][selectedCoord.ypos - 1] == -1)
	{
		resultList.push_back(Vector2(selectedCoord.xpos, selectedCoord.ypos - 1));
	}
	if (selectedCoord.ypos < 8 && board[selectedCoord.xpos][selectedCoord.ypos + 1] == -1)
	{
		resultList.push_back(Vector2(selectedCoord.xpos, selectedCoord.ypos + 1));
	}

	return resultList;
}

void Soldier::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}
