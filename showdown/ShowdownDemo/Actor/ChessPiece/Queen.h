#pragma once

#include "Actor/Piece.h"

class Queen : public Piece
{
	RTTI_DECLARATIONS(Queen, Piece)

public:
	Queen(Vector2 location);
	~Queen();

	virtual std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);
	virtual std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);

	int directions[8][2] = {
		{-1, 1},
		{-1, -1},
		{1, 1},
		{1, -1},
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
};