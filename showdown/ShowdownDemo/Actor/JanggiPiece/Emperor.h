#pragma once

#include "Actor/Piece.h"

class Emperor : public Piece
{
    RTTI_DECLARATIONS(Emperor, Piece)

public:
    Emperor(Vector2 location);
    ~Emperor();

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