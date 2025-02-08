#include "GameplayLevel.h"
#include "Engine/Engine.h"
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

/*
* Chess pieces
0: King (K)
1: Queen (Q)
2: Rook (R)
3: Bishop (B)
4: Knight (N)
5: Pawn (P)
6: Jester (J)

Janggi pieces
7: Emperor (\u6F22)
8: Cannon (\u5305)
9: Elephant (\u8C61)
10: Horse (\u99AC)
11: Chariot (\u8ECA)
12: Soldier (\u5175)
13: Gaurd (\u58EB)
*/

static Vector2 BoardPositionToLocation(int xpos, int ypos) {
    return Vector2((xpos * 4) + 2, ypos * 2 + 1);
}

GameplayLevel::GameplayLevel()
{
    board = {
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

GameplayLevel::~GameplayLevel()
{
}

void GameplayLevel::Update(float deltaTime)
{
}

void GameplayLevel::Render()
{
    Super::Render();

    // Rendering the board
    Engine::Get().Render(Vector2(0, 0), "忙式成式成式", Color::White);
    Engine::Get().Render(Vector2(26, 0), "式成式成式忖", Color::White);

    for (int i = 1; i < 9; ++i)
    {
        Engine::Get().Render(Vector2(0, i * 2), "戍式托式托式", Color::White);
        Engine::Get().Render(Vector2(26, i * 2), "式托式托式扣", Color::White);
    }

    Engine::Get().Render(Vector2(0, 18), "戌式扛式扛式", Color::White);
    Engine::Get().Render(Vector2(26, 18), "式扛式扛式戎", Color::White);

    for (int i = 1; i < 10; ++i)
    {
        for (int ix = 0; ix < 3; ++ix)
        {
            Engine::Get().Render(Vector2(ix * 4, i * 2 - 1), "弛", Color::White);
            Engine::Get().Render(Vector2(28 + ix * 4, i * 2 - 1), "弛", Color::White);
        }
    }
}
