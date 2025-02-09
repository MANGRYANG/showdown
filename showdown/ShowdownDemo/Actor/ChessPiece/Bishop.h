#pragma once

#include "Actor/Piece.h"

class Bishop : public Piece
{
	RTTI_DECLARATIONS(Bishop, Piece)

public:
	Bishop(Vector2 location);
	~Bishop();

	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);

	int directions[4][2] = {
		{-1, 1},
		{-1, -1},
		{1, 1},
		{1, -1}
	};
};