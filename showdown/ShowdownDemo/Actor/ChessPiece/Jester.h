#pragma once

#include "Actor/Piece.h"

class Jester : public Piece
{
	RTTI_DECLARATIONS(Jester, Piece)

public:
	Jester(Vector2 location);
	~Jester();
};