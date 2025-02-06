#pragma once

#include "CoreMinimal.h"
#include "Level/Level.h"
#include "Math/Vector2.h"

struct KeyState
{
	bool isKeyDown = false;
	bool wasKeyDown = false;
};

class Level;
class Actor;
class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	// Functions for managing the engine
	void Run();
	void Shutdown();
	void SetTargetFrameRate(float targetFrameRate);

	void LoadLevel(Level* newLevel);

	void AddActor(Actor* newActor);
	void DestroyActor(Actor* targetActor);

protected:
	// Functions for game loop
	void ProcessInput();
	void Update(float deltaTime);
	void Render();

	void EnableMouseInput();

	
protected:
	// Variables for managing the engine
	bool m_inShutdown;
	bool m_shouldUpdate = true;

	float m_targetFrameRate = 60.0f;
	float m_targetOneFrameTime = 0.0f;
	float m_deltaTime;

	Level* mainLevel;

	KeyState keyState[255];

	Vector2 mousePosition;
};