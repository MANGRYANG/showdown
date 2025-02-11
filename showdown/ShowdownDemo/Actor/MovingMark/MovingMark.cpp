#include "MovingMark.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

MovingMark::MovingMark(Vector2 location)
	: Super("*", location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;

	this->SetActive(false);
	this->SetColor(Color::Green);
}

MovingMark::~MovingMark()
{
}

void MovingMark::Update(float deltaTime)
{
	Super::Update(deltaTime);
}