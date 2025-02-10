#pragma once

#include "Level/GameplayLevel.h"

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