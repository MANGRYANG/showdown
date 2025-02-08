#include "Guard.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Guard::Guard(Vector2 location) : Super("\u58EB", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Guard::~Guard()
{
}
