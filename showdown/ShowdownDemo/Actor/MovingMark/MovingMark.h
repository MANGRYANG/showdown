#pragma once

#include "Actor/DrawableActor.h"
#include <vector>

class MovingMark : public DrawableActor
{
	RTTI_DECLARATIONS(MovingMark, DrawableActor)

public:
	MovingMark(Vector2 location);
	~MovingMark();

	virtual void Update(float deltaTime) override;
};