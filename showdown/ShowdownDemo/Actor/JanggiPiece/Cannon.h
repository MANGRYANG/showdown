#pragma once

#include "Actor/Piece.h"

class Cannon : public Piece
{
	RTTI_DECLARATIONS(Cannon, Piece)

public:
	Cannon(Vector2 location);
	~Cannon();
};