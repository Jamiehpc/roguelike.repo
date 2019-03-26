#include "Game.h"
#include "stdlib.h""
#include "Udp.h"
//#include <iostream>




int main()
{
   // Game game;
   // game.Run();
    Udp echo;
    int userchoice{0};
    std::cout << "Please enter: 1 for server, 2 for client" << std::endl;
    std::cin >> userchoice;

    if (userchoice == 1)
        echo.runUdpServer(4300);

    if (userchoice == 2)
        echo.runUdpClient(13000);






    return 0;
}




