#pragma once

#include "Actor/Piece.h"

class Guard : public Piece
{
	RTTI_DECLARATIONS(Guard, Piece)

public:
	Guard(Vector2 location);
	~Guard();
};