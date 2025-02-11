#pragma once

#include "Actor/Piece.h"

class Pawn : public Piece
{
	RTTI_DECLARATIONS(Pawn, Piece)

public:
	Pawn(Vector2 location);
	~Pawn();

	std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

	void SetPosition(const Vector2& newPosition);
};