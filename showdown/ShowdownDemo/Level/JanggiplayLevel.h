#pragma once

#include "Level/GameplayLevel.h"
#include <vector>

class JanggiplayLevel : public GameplayLevel
{
	// RTTI Declarations
	RTTI_DECLARATIONS(JanggiplayLevel, GameplayLevel)

public:
	JanggiplayLevel();
	~JanggiplayLevel();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};