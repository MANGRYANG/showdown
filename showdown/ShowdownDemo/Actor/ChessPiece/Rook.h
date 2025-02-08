#pragma once

#include "Actor/Piece.h"

class Rook : public Piece
{
	RTTI_DECLARATIONS(Rook, Piece)

public:
	Rook(Vector2 location);
	~Rook();
};