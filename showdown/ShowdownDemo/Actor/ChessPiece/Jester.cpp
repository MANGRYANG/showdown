#include "Jester.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Jester::Jester(Vector2 location) : Super("J", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Jester::~Jester()
{
}
