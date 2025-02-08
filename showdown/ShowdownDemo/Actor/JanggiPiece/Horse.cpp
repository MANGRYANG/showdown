#include "Horse.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Horse::Horse(Vector2 location) : Super("\u99AC", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Horse::~Horse()
{
}
