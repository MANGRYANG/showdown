#pragma once

#include "Actor/Piece.h"

class Bishop : public Piece
{
	RTTI_DECLARATIONS(Bishop, Piece)

public:
	Bishop(Vector2 location);
	~Bishop();
};