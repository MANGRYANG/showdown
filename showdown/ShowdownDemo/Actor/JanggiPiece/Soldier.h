#pragma once

#include "Actor/Piece.h"

class Soldier : public Piece
{
	RTTI_DECLARATIONS(Soldier, Piece)

public:
	Soldier(Vector2 location);
	~Soldier();

	std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;
	std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward) override;

	void SetPosition(const Vector2& newPosition);
};