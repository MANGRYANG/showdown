#pragma once

#include "Actor/Piece.h"

class Soldier : public Piece
{
	RTTI_DECLARATIONS(Soldier, Piece)

public:
	Soldier(Vector2 location);
	~Soldier();

	std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
	std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;

	void SetPosition(const Vector2& newPosition);
};