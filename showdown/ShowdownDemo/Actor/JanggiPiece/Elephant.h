#pragma once

#include "Actor/Piece.h"

class Elephant : public Piece
{
	RTTI_DECLARATIONS(Elephant, Piece)

public:
	Elephant(Vector2 location);
	~Elephant();

	std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

	int directions[8][2] = {
		{-3, -2}, {-3, 2},
		{-2, -3}, {2, -3},
		{-2, 3}, {2, 3},
		{3, -2}, {3, 2}
	};

	int leafCheckDirections[8][2] = {
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