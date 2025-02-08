#pragma once

#include "Actor/Piece.h"

class Elephant : public Piece
{
	RTTI_DECLARATIONS(Elephant, Piece)

public:
	Elephant(Vector2 location);
	~Elephant();
};