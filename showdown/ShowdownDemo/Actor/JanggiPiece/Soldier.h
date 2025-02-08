#pragma once

#include "Actor/Piece.h"

class Soldier : public Piece
{
	RTTI_DECLARATIONS(Soldier, Piece)

public:
	Soldier(Vector2 location);
	~Soldier();
};