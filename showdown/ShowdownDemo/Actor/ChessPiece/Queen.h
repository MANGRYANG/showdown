#pragma once

#include "Actor/Piece.h"

class Queen : public Piece
{
	RTTI_DECLARATIONS(Queen, Piece)

public:
	Queen(Vector2 location);
	~Queen();

	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);

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