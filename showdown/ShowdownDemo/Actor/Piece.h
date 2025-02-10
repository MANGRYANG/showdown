#pragma once

#include "Actor/DrawableActor.h"
#include <vector>

class Piece : public DrawableActor
{
	RTTI_DECLARATIONS(Piece, DrawableActor)

public:
	Piece(const char* image, Vector2 location);
	~Piece();

	virtual void Update(float deltaTime) override;
	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);

	void SetPosition(const Vector2& newPosition);
};