#pragma once

#include "Actor/Piece.h"

class Horse : public Piece
{
	RTTI_DECLARATIONS(Horse, Piece)

public:
	Horse(Vector2 location);
	~Horse();

	std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
	std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;

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