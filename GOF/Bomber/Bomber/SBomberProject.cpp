
#include <conio.h>
#include <thread>
#include <chrono>

#include "SBomber.h"
#include "MyTools.h"

#include "Logger.cpp"

using namespace std;

int main(void)
{
    Logger::getInstance().openLog("newLog.txt");
        
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(250ms);
        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    Logger::getInstance().closeLog();
    
    return 0;
}
