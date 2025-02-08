#pragma once

#include "Actor/Piece.h"

class Emperor : public Piece
{
	RTTI_DECLARATIONS(Emperor, Piece)

public:
	Emperor(Vector2 location);
	~Emperor();
};