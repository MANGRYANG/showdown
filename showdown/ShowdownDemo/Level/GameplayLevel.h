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
	void InitializeBoard();

	void SelectPiece(Vector2 targetCoord);
	void ShowReachableWays();
	void HighlightCatchableEnemies();

	void MovePiece(Vector2 destinationCoord);
	void CatchEnemyPiece(Vector2 destinationCoord);

	void Promotion();

	bool IsMarked(Vector2 targetCoord);

	bool IsThreatenedPiece(Vector2 targetCoord);

	bool IsGameOver();

	Vector2 BoardCoordToActorPosition(Vector2 boardCoord);
	Vector2 ActorPositionToBoardCoord(Vector2 actorPosition);

protected:
	int board[9][9];
	POINT mousePos;

	HWND consoleWindow = GetConsoleWindow();
	RECT consoleRect;

	Piece* currentPiece;
	std::vector<Vector2> catchablePieceCoords;
	std::vector<Vector2> reachablePieceCoords;

	// Row, Column
	Vector2 selectedBoardCoord;

	// Chess team always start first
	bool isChessTurn = true;
	bool isSelected = false;
	const bool isForward;
	
	bool isChessWin = false;
	bool isJanggiWin = false;

};