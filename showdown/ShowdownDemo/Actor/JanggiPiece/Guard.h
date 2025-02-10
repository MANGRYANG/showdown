#pragma once

#include "Actor/Piece.h"

class Guard : public Piece
{
	RTTI_DECLARATIONS(Guard, Piece)

public:
	Guard(Vector2 location);
	~Guard();

    std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;
    std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward) override;

    int directions[8][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, -1},
        {-1, 1},
        {1, 1},
        {1, -1}
    };
};