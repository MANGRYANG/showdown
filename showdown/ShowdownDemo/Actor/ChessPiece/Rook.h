#pragma once

#include "Actor/Piece.h"

class Rook : public Piece
{
	RTTI_DECLARATIONS(Rook, Piece)

public:
	Rook(Vector2 location);
	~Rook();

	virtual std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);
	virtual std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);

	int directions[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
};