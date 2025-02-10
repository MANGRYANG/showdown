#include "Piece.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Piece::Piece(const char* image, Vector2 location)
	: Super(image, location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Piece::~Piece()
{
}

void Piece::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

std::vector<std::pair<int, int>> Piece::CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	return {};
}

std::vector<std::pair<int, int>> Piece::ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward)
{
	return {};
}

void Piece::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}
