#include "JanggiplayLevel.h"

JanggiplayLevel::JanggiplayLevel(int kingdomArrangement)
    : GameplayLevel(false)
{
	int temp[9][9] = {
		{2, 4, 3, 6, 6, 6, 4, 3, 2},
		{5, 5, 5, 5, 5, 5, 5, 5, 5},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{12, -1, 12, -1, 12, -1, 12, -1, 12},
		{-1, 8, -1, -1, -1, -1, -1, 8, -1},
		{-1, -1, -1, -1, 7, -1, -1, -1, -1},
		{11, 10, 9, 13, -1, 13, 10, 9, 11},
	};

    temp[0][kingdomArrangement + 2] = 0;

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			board[i][j] = temp[i][j];
		}
	}

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            Vector2 coord = Vector2(row, col);
            switch (board[row][col])
            {
            case -1:
                GameplayLevel::AddActor(new MovingMark(BoardCoordToActorPosition(coord)));
                break;
            case 0: // King
                GameplayLevel::AddActor(new King(BoardCoordToActorPosition(coord)));
                break;
            case 1: // Queen
                GameplayLevel::AddActor(new Queen(BoardCoordToActorPosition(coord)));
                break;
            case 2: // Rook
                GameplayLevel::AddActor(new Rook(BoardCoordToActorPosition(coord)));
                break;
            case 3: // Bishop
                GameplayLevel::AddActor(new Bishop(BoardCoordToActorPosition(coord)));
                break;
            case 4: // Knight
                GameplayLevel::AddActor(new Knight(BoardCoordToActorPosition(coord)));
                break;
            case 5: // Pawn
                GameplayLevel::AddActor(new Pawn(BoardCoordToActorPosition(coord)));
                break;
            case 6: // Jester
                GameplayLevel::AddActor(new Jester(BoardCoordToActorPosition(coord)));
                break;
            case 7: // Emperor
                GameplayLevel::AddActor(new Emperor(BoardCoordToActorPosition(coord)));
                break;
            case 8: // Cannon
                GameplayLevel::AddActor(new Cannon(BoardCoordToActorPosition(coord)));
                break;
            case 9: // Elephant
                GameplayLevel::AddActor(new Elephant(BoardCoordToActorPosition(coord)));
                break;
            case 10: // Horse
                GameplayLevel::AddActor(new Horse(BoardCoordToActorPosition(coord)));
                break;
            case 11: // Chariot
                GameplayLevel::AddActor(new Chariot(BoardCoordToActorPosition(coord)));
                break;
            case 12: // Soldier
                GameplayLevel::AddActor(new Soldier(BoardCoordToActorPosition(coord)));
                break;
            case 13: // Guard
                GameplayLevel::AddActor(new Guard(BoardCoordToActorPosition(coord)));
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

	Engine::Get().Render(Vector2(12, 0), "成式成式成式成", Color::Cyan);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "托式托式托式托", ((i <= 3) ? Color::Cyan : ((i > 3 && i < 6) ? Color::White : Color::Magenta)));
	}

	Engine::Get().Render(Vector2(12, 18), "扛式扛式扛式扛", Color::Magenta);

	for (int i = 1; i < 10; ++i)
	{

		for (int ix = 0; ix < 4; ++ix)
		{
			Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "弛", ((i <= 3) ? Color::Cyan : ((i > 3 && i <= 6) ? Color::White : Color::Magenta)));
		}
	}

    // Rendering Coordination Guide
    Engine::Get().Render(Vector2(2, 19), "i   h   g   f   e   d   c   b   a", Color::Yellow);
    Engine::Get().Render(Vector2(0, 20), "________________________________________/", Color::White);

    for (int i = 0; i < 9; ++i)
    {
        Engine::Get().Render(Vector2(38, i * 2 + 1), std::to_string(i + 1).c_str(), Color::Yellow);
    }

    for (int i = 0; i < 20; ++i)
    {
        Engine::Get().Render(Vector2(40, i), "弛", Color::White);
    }
}
