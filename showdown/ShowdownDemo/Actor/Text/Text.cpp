#include "Text.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Text::Text(const char* image, Vector2 location)
	: Super(image, location)
{
	this->position.xpos = location.xpos;
	this->position.ypos = location.ypos;
}

Text::~Text()
{
}

void Text::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

void Text::SetPosition(const Vector2& newPosition)
{
	Super::SetPosition(newPosition);
}

void Text::SetColor(Color color)
{
	Super::SetColor(color);
}
