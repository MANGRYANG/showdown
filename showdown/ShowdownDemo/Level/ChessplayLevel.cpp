#include "Engine/Engine.h"
#include "ChessplayLevel.h"

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

ChessplayLevel::ChessplayLevel()
{
    int temp[9][9] = {
        {11, 9, 10, 13, -1, 13, 9, 10, 11},
        {-1, -1, -1, -1, 7, -1, -1, -1, -1},
        {-1, 8, -1, -1, -1, -1, -1, 8, -1},
        {12, -1, 12, -1, 12, -1, 12, -1, 12},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1},
        {5, 5, 5, 5, 5, 5, 5, 5, 5},
        {2, 4, 3, 6, 0, 6, 4, 3, 2}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            Super::board[i][j] = temp[i][j];
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
                GameplayLevel::AddActor(new King(BoardPositionToLocation(col, row)));
                break;
            case 2: // Rook
                GameplayLevel::AddActor(new Rook(BoardPositionToLocation(col, row)));
                break;
            case 3: // Bishop
                GameplayLevel::AddActor(new Bishop(BoardPositionToLocation(col, row)));
                break;
            case 4: // Knight
                GameplayLevel::AddActor(new Knight(BoardPositionToLocation(col, row)));
                break;
            case 5: // Pawn
                GameplayLevel::AddActor(new Pawn(BoardPositionToLocation(col, row)));
                break;
            case 6: // Jester
                GameplayLevel::AddActor(new Jester(BoardPositionToLocation(col, row)));
                break;
            case 7: // Emperor
                GameplayLevel::AddActor(new Emperor(BoardPositionToLocation(col, row)));
                break;
            case 8: // Cannon
                GameplayLevel::AddActor(new Cannon(BoardPositionToLocation(col, row)));
                break;
            case 9: // Elephant
                GameplayLevel::AddActor(new Elephant(BoardPositionToLocation(col, row)));
                break;
            case 10: // Horse
                GameplayLevel::AddActor(new Horse(BoardPositionToLocation(col, row)));
                break;
            case 11: // Chariot
                GameplayLevel::AddActor(new Chariot(BoardPositionToLocation(col, row)));
                break;
            case 12: // Soldier
                GameplayLevel::AddActor(new Soldier(BoardPositionToLocation(col, row)));
                break;
            case 13: // Guard
                GameplayLevel::AddActor(new Guard(BoardPositionToLocation(col, row)));
                break;

            default:
                break;
            }
        }
    }
    Level::ProcessAddedAndDestroyedActor();
}

ChessplayLevel::~ChessplayLevel()
{
}

void ChessplayLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void ChessplayLevel::Render()
{
	Super::Render();

	Engine::Get().Render(Vector2(12, 0), "��������������", Color::Magenta);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "��������������", ((i <= 3) ? Color::Magenta : ((i > 3 && i < 6) ? Color::White : Color::Cyan)));
	}

	Engine::Get().Render(Vector2(12, 18), "��������������", Color::Cyan);

    for (int i = 1; i < 10; ++i)
    {

        for (int ix = 0; ix < 4; ++ix)
        {
            Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "��", ((i <= 3) ? Color::Magenta : ((i > 3 && i <= 6) ? Color::White : Color::Cyan)));
        }
    }
}
