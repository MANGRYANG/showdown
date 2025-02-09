#pragma once

#include "Level/Level.h"
#include "Actor/Actor.h"
#include "Actor/Piece.h"
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
	POINT mousePos;

	HWND consoleWindow = GetConsoleWindow();
	RECT consoleRect;

	// Row, Column
	Vector2 selectedPieceIndex;

	bool isChessTurn;
};