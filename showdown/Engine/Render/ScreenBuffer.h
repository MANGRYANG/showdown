#pragma once

#include "CoreMinimal.h"
#include "Math/Vector2.h"

class ScreenBuffer
{
	friend class Engine;

public:
	ScreenBuffer(const COORD& size);
	ScreenBuffer(HANDLE console, const COORD& size);

	~ScreenBuffer();

	void SetCursorType(CursorType cursorType);

	void Draw(CHAR_INFO* buffer);
	void Clear();


private:
	HANDLE buffer;
	COORD size;
};