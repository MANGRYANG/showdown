#pragma once

#include "Actor/Piece.h"

class Pawn : public Piece
{
	RTTI_DECLARATIONS(Pawn, Piece)

public:
	Pawn(Vector2 location);
	~Pawn();

	std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
	std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
};