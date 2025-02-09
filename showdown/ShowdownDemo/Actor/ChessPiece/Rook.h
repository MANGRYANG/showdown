#pragma once

#include "Actor/Piece.h"

class Rook : public Piece
{
	RTTI_DECLARATIONS(Rook, Piece)

public:
	Rook(Vector2 location);
	~Rook();

	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);

	int directions[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
};