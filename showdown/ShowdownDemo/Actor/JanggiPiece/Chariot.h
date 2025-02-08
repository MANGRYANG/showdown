#pragma once

#include "Actor/Piece.h"

class Chariot : public Piece
{
	RTTI_DECLARATIONS(Chariot, Piece)

public:
	Chariot(Vector2 location);
	~Chariot();
};