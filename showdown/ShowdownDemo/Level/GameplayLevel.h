#pragma once

#include "Level/Level.h"
#include <vector>

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
	std::vector<std::vector<int>> board;
};