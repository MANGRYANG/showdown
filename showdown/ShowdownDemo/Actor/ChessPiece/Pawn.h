#pragma once

#include "Actor/Piece.h"

class Pawn : public Piece
{
	RTTI_DECLARATIONS(Pawn, Piece)

public:
	Pawn(Vector2 location);
	~Pawn();
};