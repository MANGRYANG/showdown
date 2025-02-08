#pragma once

#include "Actor/Piece.h"

class King : public Piece
{
	RTTI_DECLARATIONS(King, Piece)

public:
	King(Vector2 location);
	~King();
};