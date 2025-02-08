#pragma once

#include "Level/GameplayLevel.h"
#include <vector>

class ChessplayLevel : public GameplayLevel
{
	// RTTI Declarations
	RTTI_DECLARATIONS(ChessplayLevel, GameplayLevel)

public:
	ChessplayLevel();
	~ChessplayLevel();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};