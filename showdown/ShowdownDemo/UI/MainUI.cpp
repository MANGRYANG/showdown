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

    std::cout << "1- Multiplay Mode\n2- Practice Mode\nEnter (1 / 2): ";
    std::cin >> gamemode_opt;

    if (std::cin.fail() || (gamemode_opt != 1 && gamemode_opt != 2)) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        PrintLine();
        std::cout << "Invalid option, please enter a valid option." << std::endl;
        goto SELECT_GAMEMODE;
    }

    if (gamemode_opt == 1)
    {
        PrintLine();

        std::cout << "Enter your name: ";
        std::cin >> player_name;

        PrintLine();

        std::cout << "1- Search for players\n2- Invite a player\nEnter (1 / 2): ";
        std::cin >> opt;

        if (std::cin.fail() || (opt != 1 && opt != 2)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            PrintLine();
            std::cout << "Invalid option, please enter a valid option." << std::endl;
            goto SELECT_GAMEMODE;
        }

        PrintLine();

        // TODO : In development..
        std::cout << "Still development..." << std::endl;

        PrintLine();

        goto SELECT_GAMEMODE;
    }
    else if (gamemode_opt == 2)
    {
    SELECT_SIDE:
        PrintLine();

        std::cout << "1- Start with chess\n2- Start with janggi\nEnter (1 / 2): ";
        std::cin >> opt;

        if (std::cin.fail() || (opt != 1 && opt != 2))
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            PrintLine();
            std::cout << "Invalid option, please enter a valid option." << std::endl;
            goto SELECT_SIDE;
        }

        PrintLine();

        std::cout << "Configuring the game.." << std::endl;

        PrintLine();

        Sleep(1000);

        SingleplayGame singleplayGame;

        if (opt == 1)
        {
            singleplayGame.LoadLevel(new ChessplayLevel());
        }

        else if (opt == 2)
        {
            singleplayGame.LoadLevel(new JanggiplayLevel());
        }

        singleplayGame.Run();

    }
    else
    {
        PrintLine();

        std::cout << "Invalid option, please enter a valid option." << std::endl;

        PrintLine();

        goto SELECT_GAMEMODE;
    }
}

void MainUI::PrintLine()
{
    std::cout << "===================================================================\n";
}
