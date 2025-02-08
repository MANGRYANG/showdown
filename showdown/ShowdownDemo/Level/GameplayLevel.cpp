#include "GameplayLevel.h"
#include "Engine/Engine.h"

GameplayLevel::GameplayLevel()
{
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
