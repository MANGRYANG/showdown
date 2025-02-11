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
	virtual std::vector<Vector2> CatchablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);
	virtual std::vector<Vector2> ReachablePieceCoord(int board[][9], Vector2 selectedCoord, bool isForward);

	void SetPosition(const Vector2& newPosition);

	void SetColor(Color color);
};