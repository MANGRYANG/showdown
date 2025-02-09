#pragma once

#include "Level/Level.h"
#include "Actor/Actor.h"
#include "Actor/Piece.h"
#include "Actor/MovingMark/MovingMark.h"
#include "Math/Vector2.h"

class GameplayLevel : public Level
{
	// RTTI Declarations
	RTTI_DECLARATIONS(GameplayLevel, Level)

public:
	GameplayLevel(bool isForward);
	~GameplayLevel();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

protected:
	Vector2 BoardCoordToPosition(int xpos, int ypos);
	Vector2 PositionToBoardCoord(Vector2 position);

protected:
	int board[9][9];
	POINT mousePos;

	HWND consoleWindow = GetConsoleWindow();
	RECT consoleRect;

	Piece* currentPiece;
	std::vector<std::pair<int, int>> catchablePositions;
	std::vector<std::pair<int, int>> movingMarkPositions;

	// Row, Column
	Vector2 selectedPieceIndex;

	bool isChessTurn;
	bool isSelected = false;
	const bool isForward;
};