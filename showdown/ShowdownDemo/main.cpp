#include "Game/SingleplayGame.h"
#include "Level/ChessplayLevel.h"
#include "Level/JanggiplayLevel.h"

void static PrintLine()
{
    std::cout << "===================================================================\n";
}

char player_name[1024];
char guest_name[1024];
int gamemode_opt = 0;
int opt = 0;

int main(void)
{
    SetConsoleTitle("Showdown");
    system("mode con:cols=150 lines=40");
    std::cout << R"(
  .     ______ _                     _                         
 /\\   / _____) |                   | |                  ___ __ __       
( ( ) ( (____ | |__   ___  _ _ _  __| | ___  _ _ _ ____  \  \  \  \     
 \\/   \____ \|  _ \ / _ \| | | |/ _  |/ _ \| | | |  _ \  \  \  \  \   
  ,    _____) ) | | | |_| | | | ( (_| | |_| | | | | | | |  )  )  )  )   
      (______/|_| |_|\___/ \___/ \____|\___/ \___/|_| |_| /  /  /  /     
=========================================================/__/__/__/    
)";

    // Green: 10
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << ":: Showdown ::" << "                                              ";
    // White: 15
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "(v1.0.0)\n" << std::endl;

    SELECT_GAMEMODE:
    
    std::cout << "1- Multiplay Mode\n2- Practice Mode\nEnter (1 / 2): ";
    std::cin >> gamemode_opt;

    if (gamemode_opt == 1)
    {
        PrintLine();
        
        std::cout << "Enter your name: ";
        std::cin >> player_name;
        
        PrintLine();
        
        std::cout << "1- Search for players\n2- Invite a player\nEnter (1 / 2): ";
        std::cin >> opt;
        
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

        if (opt != 1 && opt != 2)
        {
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

    return 0;
}