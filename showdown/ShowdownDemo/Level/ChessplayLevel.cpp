#include "Engine/Engine.h"
#include "ChessplayLevel.h"

ChessplayLevel::ChessplayLevel()
{
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

	Engine::Get().Render(Vector2(12, 0), "��������������", Color::Red);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "��������������", ((i <= 3) ? Color::Red : ((i > 3 && i < 6) ? Color::White : Color::Green)));
	}

	Engine::Get().Render(Vector2(12, 18), "��������������", Color::Green);

    for (int i = 1; i < 10; ++i)
    {

        for (int ix = 0; ix < 4; ++ix)
        {
            Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "��", ((i <= 3) ? Color::Red : ((i > 3 && i <= 6) ? Color::White : Color::Green)));
        }
    }
}
