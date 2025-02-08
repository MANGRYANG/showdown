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
