
#include <conio.h>
#include <thread>
#include <chrono>

#include "SBomber.h"
#include "MyTools.h"
#include "LoggerSingleton.cpp"
#include "Logger.cpp"

using namespace std;

//========================================================================================================================

int main(void)
{
    FileLoggerSingleton::getInstance().OpenLogFile("log.txt");

    Logger::getInstance().openLog("newLog.txt");
    Logger::getInstance().write("We made it!");
    Logger::getInstance().write("Are not we?! ", 5);
    Logger::getInstance().write("OK then ", 5.6);        
    
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
    FileLoggerSingleton::getInstance().CloseLogFile();

    return 0;
}
