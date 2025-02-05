#pragma once

#include "CoreMinimal.h"

class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	// Functions for managing the engine
	void Run();
	void Shutdown();
	void SetTargetFrameRate(float targetFrameRate);

protected:
	// Functions for game loop
	void ProcessInput();
	void Update(float deltaTime);
	void Render();

	
protected:
	// Variables for managing the engine
	bool m_inShutdown;
	bool m_shouldUpdate = true;

	float m_targetFrameRate = 60.0f;
	float m_targetOneFrameTime = 0.0f;
	float m_deltaTime;
};