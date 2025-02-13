#pragma once

#include "Level/GameplayLevel.h"

class ChessplayLevel : public GameplayLevel
{
	// RTTI Declarations
	RTTI_DECLARATIONS(ChessplayLevel, GameplayLevel)

public:
	ChessplayLevel(int kingdomArrangement);
	~ChessplayLevel();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};