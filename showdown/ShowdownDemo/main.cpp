#include "Game/Game.h"

void static PrintLine()
{
    std::cout << "===================================================================\n";
}

int main(void)
{
    SetConsoleTitle("Showdown");
    system("mode con:cols=144 lines=40");
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
	std::cout << "(v1.0.0)" << std::endl;

    Game game;
    game.Run();
}