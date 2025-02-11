#pragma once

#include "Actor/Piece.h"

class King : public Piece
{
	RTTI_DECLARATIONS(King, Piece)

public:
	King(Vector2 location);
	~King();

	std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

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