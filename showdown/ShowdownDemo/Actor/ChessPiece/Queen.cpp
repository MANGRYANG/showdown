#include "Queen.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Queen::Queen(Vector2 location) : Super("Q", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Queen::~Queen()
{
}
