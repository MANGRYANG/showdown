#include "Emperor.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Emperor::Emperor(Vector2 location) : Super("\u6F22", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Emperor::~Emperor()
{
}
