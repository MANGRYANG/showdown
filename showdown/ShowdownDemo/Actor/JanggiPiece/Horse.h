#pragma once

#include "Actor/Piece.h"

class Horse : public Piece
{
	RTTI_DECLARATIONS(Horse, Piece)

public:
	Horse(Vector2 location);
	~Horse();
};