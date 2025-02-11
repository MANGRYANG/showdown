#pragma once

#include "Actor/Piece.h"

class Bishop : public Piece
{
	RTTI_DECLARATIONS(Bishop, Piece)

public:
	Bishop(Vector2 location);
	~Bishop();

	virtual std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	virtual std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

	int directions[4][2] = {
		{-1, 1},
		{-1, -1},
		{1, 1},
		{1, -1}
	};
};