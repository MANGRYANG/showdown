#include "Elephant.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Elephant::Elephant(Vector2 location) : Super("\u8C61", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Elephant::~Elephant()
{
}
