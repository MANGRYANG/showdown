#pragma once

#include "Engine/Engine.h"

#include "Level/Level.h"

#include "Actor/Actor.h"
#include "Actor/Piece.h"
#include "Actor/MovingMark/MovingMark.h"
#include "Actor/Text/Text.h"

#include "Actor/ChessPiece/King.h"
#include "Actor/ChessPiece/Queen.h"
#include "Actor/ChessPiece/Rook.h"
#include "Actor/ChessPiece/Bishop.h"
#include "Actor/ChessPiece/Knight.h"
#include "Actor/ChessPiece/Pawn.h"
#include "Actor/ChessPiece/Jester.h"

#include "Actor/JanggiPiece/Emperor.h"
#include "Actor/JanggiPiece/Cannon.h"
#include "Actor/JanggiPiece/Elephant.h"
#include "Actor/JanggiPiece/Horse.h"
#include "Actor/JanggiPiece/Chariot.h"
#include "Actor/JanggiPiece/Soldier.h"
#include "Actor/JanggiPiece/Guard.h"

#include "Math/Vector2.h"

#include <conio.h>
#include <chrono>
#include <thread>
#include <string>

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

	void SetNotationDefault(Vector2 startCoord, Vector2 endCoord, bool isCapture);
	void PrintNotation();

	void Promotion();

	void CheckStatusSetting();

	void TimerFunction();

	void SetTrianglePosition();

	bool IsMarked(Vector2 targetCoord);

	bool IsThreatenedPiece(Vector2 targetCoord);

	bool IsGameOver();

	Vector2 BoardCoordToActorPosition(Vector2 boardCoord);
	Vector2 ActorPositionToBoardCoord(Vector2 actorPosition);

	Vector2 TextLinePositionSetting(int line, Vector2 startPosition);

	std::string DoubleToTime(double timeDouble);

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

	Vector2 notationMessagePosition = Vector2(46, 1);
	Vector2 firstTimeMessagePosition = Vector2(2, 22);
	Vector2 secondTimeMessagePosition = Vector2(2, 24);
	Vector2 firstTimerPosition = Vector2(20, 22);
	Vector2 secondTimerPosition = Vector2(20, 24);
	Vector2 gameOverMessagePosition = Vector2(2, 27);

	std::string notationCounterText;
	std::string currentNotation = "";
	int notationCount = 0;

	// Chess team always start first
	bool isChessTurn = true;
	bool isSelected = false;
	const bool isForward;

	bool isChessWin = false;
	bool isJanggiWin = false;

	bool isLevelStopped = false;

	std::thread timerThread;
	std::atomic<bool> timerRunning{ true };

	double timeLimitForChess = 60000.0;
	double timeLimitForJanggi = 60000.0;

	Text firstText = Text("10 : 00 : 00", firstTimerPosition);
	Text secondText = Text("10 : 00 : 00", secondTimerPosition);
};