#include "Rook.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Rook::Rook(Vector2 location) : Super("R", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Rook::~Rook()
{
}
