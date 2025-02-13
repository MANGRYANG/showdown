#pragma once

#include "Engine/Engine.h"
#include "Level/Level.h"
#include "Level/ChessplayLevel.h"
#include "Level/JanggiplayLevel.h"
#include "Game/SingleplayGame.h"

class MainUI : public Level
{
public:
	MainUI(unsigned int major, unsigned int minor, unsigned int patch);
	~MainUI();

private:
	void SettingConsole();
	void PrintASCII();
	void PrintVersionInfo(unsigned int major, unsigned int minor, unsigned int patch);
	void ShowMenu();
	void PrintText(const char* text);
	void PrintLine();

	char player_name[1024];
	char guest_name[1024];

	int gamemode_opt = 0;
	int opt = 0;
	int kingdomPosition = 1;
};