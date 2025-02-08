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
    Engine::Get().Render(Vector2(0, 0), "������������", Color::White);
    Engine::Get().Render(Vector2(26, 0), "������������", Color::White);

    for (int i = 1; i < 9; ++i)
    {
        Engine::Get().Render(Vector2(0, i * 2), "������������", Color::White);
        Engine::Get().Render(Vector2(26, i * 2), "������������", Color::White);
    }

    Engine::Get().Render(Vector2(0, 18), "������������", Color::White);
    Engine::Get().Render(Vector2(26, 18), "������������", Color::White);

    for (int i = 1; i < 10; ++i)
    {
        for (int ix = 0; ix < 3; ++ix)
        {
            Engine::Get().Render(Vector2(ix * 4, i * 2 - 1), "��", Color::White);
            Engine::Get().Render(Vector2(28 + ix * 4, i * 2 - 1), "��", Color::White);
        }
    }
}
