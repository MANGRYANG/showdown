#include "King.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

King::King(Vector2 location) : Super("K", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

King::~King()
{
}
