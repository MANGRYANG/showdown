#pragma once

#include "Actor/Piece.h"

class Guard : public Piece
{
	RTTI_DECLARATIONS(Guard, Piece)

public:
	Guard(Vector2 location);
	~Guard();

    std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
    std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

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