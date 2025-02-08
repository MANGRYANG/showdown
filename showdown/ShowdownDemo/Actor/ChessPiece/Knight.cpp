#include "Knight.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Knight::Knight(Vector2 location) : Super("N", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Knight::~Knight()
{
}
