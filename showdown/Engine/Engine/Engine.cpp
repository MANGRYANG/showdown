#include "PCH.h"
#include "Engine.h"
#include "Actor/Actor.h"

#include <conio.h>

Engine::Engine()
	: m_inShutdown(false)
{
	SetTargetFrameRate(60.0f);
}

Engine::~Engine()
{
}

void Engine::Run()
{
	LARGE_INTEGER frequency, time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	EnableMouseInput();

	while (true)
	{
		if (m_inShutdown)
		{
			break;
		}

		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		m_deltaTime = static_cast<float>(currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart);

		if (m_deltaTime >= m_targetOneFrameTime)
		{
			ProcessInput();
			if (m_shouldUpdate)
			{
				Update(m_deltaTime);
				Render();
			}

			previousTime = currentTime;

			m_shouldUpdate = true;
		}
	}
}

void Engine::Shutdown()
{
	m_inShutdown = true;
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	m_targetFrameRate = targetFrameRate;
	m_targetOneFrameTime = 1.0f / targetFrameRate;
}

void Engine::LoadLevel(Level* newLevel)
{
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	targetActor->Destroy();
}

void Engine::ProcessInput()
{
	static HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);

	INPUT_RECORD record;
	DWORD events;
	if (PeekConsoleInput(inputHandle, &record, 1, &events) && events > 0)
	{
		if (ReadConsoleInput(inputHandle, &record, 1, &events))
		{
			switch (record.EventType)
			{
			case KEY_EVENT:
			{
				if (record.Event.KeyEvent.bKeyDown)
				{
					keyState[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = true;
				}
				else
				{
					keyState[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = false;
				}
			}
			break;

			case MOUSE_EVENT:
			{
				mousePosition.xpos = record.Event.MouseEvent.dwMousePosition.X;
				mousePosition.ypos = record.Event.MouseEvent.dwMousePosition.Y;

				keyState[VK_LBUTTON].isKeyDown
					= (record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) != 0;
			}
			break;
			}
		}
	}
}

void Engine::Update(float deltaTime)
{
}

void Engine::Render()
{
}

void Engine::EnableMouseInput()
{
	HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);

	DWORD mode;
	GetConsoleMode(inputHandle, &mode);
	SetConsoleMode(inputHandle, mode | ENABLE_MOUSE_INPUT);
}
