#include "Cannon.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Cannon::Cannon(Vector2 location) : Super("\u5305", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Cannon::~Cannon()
{
}
