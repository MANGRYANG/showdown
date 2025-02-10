#pragma once

#include "Actor/Piece.h"

class Emperor : public Piece
{
    RTTI_DECLARATIONS(Emperor, Piece)

public:
    Emperor(Vector2 location);
    ~Emperor();

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