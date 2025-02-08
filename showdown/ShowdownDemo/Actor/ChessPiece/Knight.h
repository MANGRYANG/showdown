#pragma once

#include "Actor/Piece.h"

class Knight : public Piece
{
	RTTI_DECLARATIONS(Knight, Piece)

public:
	Knight(Vector2 location);
	~Knight();
};