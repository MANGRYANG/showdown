#pragma once

#include "Actor/Piece.h"

class Chariot : public Piece
{
	RTTI_DECLARATIONS(Chariot, Piece)

public:
	Chariot(Vector2 location);
	~Chariot();

	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);

	int directions[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	int innerDiagonalDirections[4][2] = {
		{-1, -1},
		{-1, 1},
		{1, 1},
		{1, -1}
	};
};