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

std::vector<Vector2> Piece::CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	return {};
}

std::vector<Vector2> Piece::ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward)
{
	return {};
}

void Piece::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}

void Piece::SetColor(Color color)
{
	Super::SetColor(color);
}
