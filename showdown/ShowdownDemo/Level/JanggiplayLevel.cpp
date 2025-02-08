#include "Engine/Engine.h"
#include "JanggiplayLevel.h"

JanggiplayLevel::JanggiplayLevel()
{
}

JanggiplayLevel::~JanggiplayLevel()
{
}

void JanggiplayLevel::Update(float deltaTime)
{
}

void JanggiplayLevel::Render()
{
	Super::Render();

	Engine::Get().Render(Vector2(12, 0), "��������������", Color::Green);

	for (int i = 1; i < 9; ++i)
	{
		Engine::Get().Render(Vector2(12, i * 2), "��������������", ((i <= 3) ? Color::Green : ((i > 3 && i < 6) ? Color::White : Color::Red)));
	}

	Engine::Get().Render(Vector2(12, 18), "��������������", Color::Red);

	for (int i = 1; i < 10; ++i)
	{

		for (int ix = 0; ix < 4; ++ix)
		{
			Engine::Get().Render(Vector2(12 + ix * 4, i * 2 - 1), "��", ((i <= 3) ? Color::Green : ((i > 3 && i <= 6) ? Color::White : Color::Red)));
		}
	}
}
