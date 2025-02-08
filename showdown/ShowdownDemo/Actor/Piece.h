#pragma once

#include "Actor/DrawableActor.h"

class Piece : public DrawableActor
{
	RTTI_DECLARATIONS(Piece, DrawableActor)

public:
	Piece(const char* image, Vector2 location);
	~Piece();

	virtual void Update(float deltaTime) override;
};