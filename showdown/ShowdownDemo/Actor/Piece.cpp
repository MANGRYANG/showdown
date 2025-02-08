#include "Piece.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Piece::Piece(const char* image, Vector2 location) : Super(image)
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