#pragma once

#include "Actor/Piece.h"

class Horse : public Piece
{
	RTTI_DECLARATIONS(Horse, Piece)

public:
	Horse(Vector2 location);
	~Horse();

	std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

	int directions[8][2] = {
		{-2, -1}, {-2, 1},
		{-1, -2}, {1, -2},
		{-1, 2}, {1, 2},
		{2, -1}, {2, 1}
	};

	int checkDirections[4][2] = {
		{-1, 0},
		{0, -1},
		{0, 1},
		{1, 0}
	};
};