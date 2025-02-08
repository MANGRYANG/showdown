#pragma once

#include "Level/Level.h"
#include "Math/Vector2.h"

class GameplayLevel : public Level
{
	// RTTI Declarations
	RTTI_DECLARATIONS(GameplayLevel, Level)

public:
	GameplayLevel();
	~GameplayLevel();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

protected:
	Vector2 BoardPositionToLocation(int xpos, int ypos);

protected:
	int board[9][9];
};