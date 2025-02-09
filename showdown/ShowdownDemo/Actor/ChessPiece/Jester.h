#pragma once

#include "Actor/Piece.h"

class Jester : public Piece
{
	RTTI_DECLARATIONS(Jester, Piece)

public:
	Jester(Vector2 location);
	~Jester();

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