#include "MovingMark.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

MovingMark::MovingMark(Vector2 location)
	: Super("*", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

MovingMark::~MovingMark()
{
}

void MovingMark::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

std::vector<std::pair<int, int>> MovingMark::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	return {};
}

std::vector<std::pair<int, int>> MovingMark::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	return {};
}
