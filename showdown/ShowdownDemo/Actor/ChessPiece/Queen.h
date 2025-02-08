#pragma once

#include "Actor/Piece.h"

class Queen : public Piece
{
	RTTI_DECLARATIONS(Queen, Piece)

public:
	Queen(Vector2 location);
	~Queen();
};