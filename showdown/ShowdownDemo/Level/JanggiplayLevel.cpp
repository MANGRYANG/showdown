#include "Engine/Engine.h"
#include "JanggiplayLevel.h"

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

JanggiplayLevel::JanggiplayLevel()
    : GameplayLevel(false)
{
	int temp[9][9] = {
		{2, 4, 3, 6, 0, 6, 4, 3, 2},
		{5, 5, 5, 5, 5, 5, 5, 5, 5},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{12, -1, 12, -1, 12, -1, 12, -1, 12},
		{-1, 8, -1, -1, -1, -1, -1, 8, -1},
		{-1, -1, -1, -1, 7, -1, -1, -1, -1},
		{11, 9, 10, 13, -1, 13, 9, 10, 11},
	};

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			board[i][j] = temp[i][j];
		}
	}

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            switch (board[row][col])
            {
            case -1:
                break;
            case 0: // King
                GameplayLevel::AddActor(new King(BoardCoordToPosition(col, row)));
                break;
            case 2: // Rook
                GameplayLevel::AddActor(new Rook(BoardCoordToPosition(col, row)));
                break;
            case 3: // Bishop
                GameplayLevel::AddActor(new Bishop(BoardCoordToPosition(col, row)));
                break;
            case 4: // Knight
                GameplayLevel::AddActor(new Knight(BoardCoordToPosition(col, row)));
                break;
            case 5: // Pawn
                GameplayLevel::AddActor(new Pawn(BoardCoordToPosition(col, row)));
                break;
            case 6: // Jester
                GameplayLevel::AddActor(new Jester(BoardCoordToPosition(col, row)));
                break;
            case 7: // Emperor
                GameplayLevel::AddActor(new Emperor(BoardCoordToPosition(col, row)));
                break;
            case 8: // Cannon
                GameplayLevel::AddActor(new Cannon(BoardCoordToPosition(col, row)));
                break;
            case 9: // Elephant
                GameplayLevel::AddActor(new Elephant(BoardCoordToPosition(col, row)));
                break;
            case 10: // Horse
                GameplayLevel::AddActor(new Horse(BoardCoordToPosition(col, row)));
                break;
            case 11: // Chariot
                GameplayLevel::AddActor(new Chariot(BoardCoordToPosition(col, row)));
                break;
            case 12: // Soldier
                GameplayLevel::AddActor(new Soldier(BoardCoordToPosition(col, row)));
                break;
            case 13: // Guard
                GameplayLevel::AddActor(new Guard(BoardCoordToPosition(col, row)));
                break;

            default:
                break;
            }
        }
    }
    Level::ProcessAddedAndDestroyedActor();
}

JanggiplayLevel::~JanggiplayLevel()
{
}

void JanggiplayLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void JanggiplayLevel::Render()
{
	Super::Render();

	Engine::Get().Render(Vector2(12, 0), "��������������", Color::Cyan);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "��������������", ((i <= 3) ? Color::Cyan : ((i > 3 && i < 6) ? Color::White : Color::Magenta)));
	}

	Engine::Get().Render(Vector2(12, 18), "��������������", Color::Magenta);

	for (int i = 1; i < 10; ++i)
	{

		for (int ix = 0; ix < 4; ++ix)
		{
			Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "��", ((i <= 3) ? Color::Cyan : ((i > 3 && i <= 6) ? Color::White : Color::Magenta)));
		}
	}
}
