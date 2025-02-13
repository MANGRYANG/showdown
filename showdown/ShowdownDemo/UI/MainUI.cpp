#include "MainUI.h"

MainUI::MainUI(unsigned int major, unsigned int minor, unsigned int patch)
{
    SettingConsole();
    PrintASCII();
    PrintVersionInfo(major, minor, patch);
    ShowMenu();
}

MainUI::~MainUI()
{
}

void MainUI::SettingConsole()
{
    SetConsoleTitle("Showdown");
    system("mode con:cols=150 lines=40");
}

void MainUI::PrintASCII()
{
    std::cout << R"(
  .     ______ _                     _                         
 /\\   / _____) |                   | |                  ___ __ __       
( ( ) ( (____ | |__   ___  _ _ _  __| | ___  _ _ _ ____  \  \  \  \     
 \\/   \____ \|  _ \ / _ \| | | |/ _  |/ _ \| | | |  _ \  \  \  \  \   
  ,    _____) ) | | | |_| | | | ( (_| | |_| | | | | | | |  )  )  )  )   
      (______/|_| |_|\___/ \___/ \____|\___/ \___/|_| |_| /  /  /  /     
=========================================================/__/__/__/    
)";

}

void MainUI::PrintVersionInfo(unsigned int major, unsigned int minor, unsigned int patch)
{
    std::string versionInfo = "(v" + std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch) + ")";
    // Green: 10
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    std::cout << ":: Showdown ::" << "                                              ";
    // White: 15
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << versionInfo << "\n" << std::endl;
}

void MainUI::ShowMenu()
{
SELECT_GAMEMODE:

    PrintText("1- Multiplay Mode\n2- Practice Mode\nEnter (1 / 2): ");
    std::cin >> gamemode_opt;

    if (std::cin.fail() || (gamemode_opt != 1 && gamemode_opt != 2)) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        PrintLine();
        PrintText("Invalid option, please enter a valid option.\n");
        PrintLine();
        goto SELECT_GAMEMODE;
    }

    PrintLine();

    if (gamemode_opt == 1)
    {
        PrintText("Enter your name: ");
        std::cin >> player_name;

        PrintLine();

        MULTIPLAY_GAMEMODE:

        PrintText("1- Search for players\n2- Invite a player\nEnter (1 / 2): ");
        std::cin >> opt;

        if (std::cin.fail() || (opt != 1 && opt != 2)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            PrintLine();
            PrintText("Invalid option, please enter a valid option.\n");
            PrintLine();
            goto MULTIPLAY_GAMEMODE;
        }

        PrintLine();

        // TODO : In development..
        PrintText("Still development...");

        PrintLine();

        goto SELECT_GAMEMODE;
    }
    else if (gamemode_opt == 2)
    {
        SELECT_SIDE:

        PrintText("1- Start with chess\n2- Start with janggi\nEnter (1 / 2): ");
        std::cin >> opt;

        if (std::cin.fail() || (opt != 1 && opt != 2))
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            PrintLine();
            PrintText("Invalid option, please enter a valid option.\n");
            PrintLine();
            goto SELECT_SIDE;
        }

        PrintLine();

        SELECT_KINGDOMPOSITION:
        
        PrintText("Select kingdom's position\n1- King Jester Jester\n2- Jester King Jester\n3- Jester Jester King\nEnter (1 / 2 / 3): ");

        std::cin >> kingdomPosition;

        if (std::cin.fail() || (kingdomPosition != 1 && kingdomPosition != 2 && kingdomPosition != 3))
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            PrintLine();
            PrintText("Invalid option, please enter a valid option.\n");
            PrintLine();
            goto SELECT_KINGDOMPOSITION;
        }

        PrintLine();

        PrintText("Configuring the game..\n");

        PrintLine();

        Sleep(1000);

        PrintText("Complete!\n");

        PrintLine();

        Sleep(300);

        SingleplayGame singleplayGame;

        if (opt == 1)
        {
            singleplayGame.LoadLevel(new ChessplayLevel(kingdomPosition));
        }

        else if (opt == 2)
        {
            singleplayGame.LoadLevel(new JanggiplayLevel(kingdomPosition));
        }

        singleplayGame.Run();

    }
    else
    {
        PrintText("Invalid option, please enter a valid option.");

        PrintLine();

        goto SELECT_GAMEMODE;
    }
}

void MainUI::PrintText(const char* text)
{
    for (int idx = 0; idx < strlen(text); ++idx)
    {
        std::cout << text[idx];
        Sleep((text[idx] == ' ') ? 150 : 50);
    }
}

void MainUI::PrintLine()
{
    std::cout << "===================================================================\n";
}
