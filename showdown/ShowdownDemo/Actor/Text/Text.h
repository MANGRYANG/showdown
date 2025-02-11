#pragma once

#include "Actor/DrawableActor.h"
#include <vector>

class Text : public DrawableActor
{
	RTTI_DECLARATIONS(Text, DrawableActor)

public:
	Text(const char* image, Vector2 location);
	Text(const char* image, Vector2 location, Color color);
	~Text();

	virtual void Update(float deltaTime) override;

	void SetPosition(const Vector2& newPosition);

	void SetColor(Color color);
};