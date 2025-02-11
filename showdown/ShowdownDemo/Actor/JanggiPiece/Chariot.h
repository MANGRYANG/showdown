#pragma once

#include "Actor/Piece.h"

class Chariot : public Piece
{
	RTTI_DECLARATIONS(Chariot, Piece)

public:
	Chariot(Vector2 location);
	~Chariot();

	virtual std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);
	virtual std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);

	int directions[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	int innerDiagonalDirections[4][2] = {
		{-1, -1},
		{-1, 1},
		{1, 1},
		{1, -1}
	};
};