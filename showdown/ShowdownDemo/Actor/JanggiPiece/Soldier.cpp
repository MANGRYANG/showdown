#include "Soldier.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Soldier::Soldier(Vector2 location) : Super("\u5175", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Soldier::~Soldier()
{
}
