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
                Level::AddActor(new King(BoardPositionToLocation(col, row)));
                break;
            case 2: // Rook
                Level::AddActor(new Rook(BoardPositionToLocation(col, row)));
                break;
            case 3: // Bishop
                Level::AddActor(new Bishop(BoardPositionToLocation(col, row)));
                break;
            case 4: // Knight
                Level::AddActor(new Knight(BoardPositionToLocation(col, row)));
                break;
            case 5: // Pawn
                Level::AddActor(new Pawn(BoardPositionToLocation(col, row)));
                break;
            case 6: // Jester
                Level::AddActor(new Jester(BoardPositionToLocation(col, row)));
                break;
            case 7: // Emperor
                Level::AddActor(new Emperor(BoardPositionToLocation(col, row)));
                break;
            case 8: // Cannon
                Level::AddActor(new Cannon(BoardPositionToLocation(col, row)));
                break;
            case 9: // Elephant
                Level::AddActor(new Elephant(BoardPositionToLocation(col, row)));
                break;
            case 10: // Horse
                Level::AddActor(new Horse(BoardPositionToLocation(col, row)));
                break;
            case 11: // Chariot
                Level::AddActor(new Chariot(BoardPositionToLocation(col, row)));
                break;
            case 12: // Soldier
                Level::AddActor(new Soldier(BoardPositionToLocation(col, row)));
                break;
            case 13: // Guard
                Level::AddActor(new Guard(BoardPositionToLocation(col, row)));
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
}

void ChessplayLevel::Render()
{
	Super::Render();

	Engine::Get().Render(Vector2(12, 0), "成式成式成式成", Color::Red);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "托式托式托式托", ((i <= 3) ? Color::Red : ((i > 3 && i < 6) ? Color::White : Color::Green)));
	}

	Engine::Get().Render(Vector2(12, 18), "扛式扛式扛式扛", Color::Green);

    for (int i = 1; i < 10; ++i)
    {

        for (int ix = 0; ix < 4; ++ix)
        {
            Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "弛", ((i <= 3) ? Color::Red : ((i > 3 && i <= 6) ? Color::White : Color::Green)));
        }
    }
}
