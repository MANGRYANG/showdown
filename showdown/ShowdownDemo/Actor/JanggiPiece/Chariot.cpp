#include "Chariot.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Chariot::Chariot(Vector2 location) : Super("\u8ECA", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Chariot::~Chariot()
{
}
