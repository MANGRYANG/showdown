#pragma once

#include "Actor/DrawableActor.h"
#include <vector>

class MovingMark : public DrawableActor
{
	RTTI_DECLARATIONS(MovingMark, DrawableActor)

public:
	MovingMark(Vector2 location);
	~MovingMark();

	virtual void Update(float deltaTime) override;
	virtual std::vector<std::pair<int, int>> CatchablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
	virtual std::vector<std::pair<int, int>> ReachablePiecePosition(int board[][9], int selectedRow, int selectedCol, bool isForward);
};