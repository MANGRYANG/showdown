#pragma once

#include "Actor/Piece.h"

class King : public Piece
{
	RTTI_DECLARATIONS(King, Piece)

public:
	King(Vector2 location);
	~King();

	std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
	std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;

    int directions[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
};