#include "PCH.h"
#include "Engine.h"

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
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	m_targetFrameRate = targetFrameRate;
	m_targetOneFrameTime = 1.0f / targetFrameRate;
}

void Engine::ProcessInput()
{
}

void Engine::Update(float deltaTime)
{
}

void Engine::Render()
{
	std::cout << "Rendering" << std::endl;
}
