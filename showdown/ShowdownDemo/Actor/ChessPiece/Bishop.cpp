#include "Bishop.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Bishop::Bishop(Vector2 location) : Super("B", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Bishop::~Bishop()
{
}
