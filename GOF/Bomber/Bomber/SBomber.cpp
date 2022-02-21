
#include <conio.h>
#include <windows.h>
#include <memory>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "TankAdapter.h"

#include "LoggerSingleton.cpp"
#include "Logger.cpp"
#include "Commands.h"
#include "BombDecorator.h"
#include "RealBomb.h"
#include "HouseDirector.h"
#include "CollisionDetector.h"

using namespace std;
using namespace MyTools;

SBomber::SBomber()
    : exitFlag(false),
    startTime(0),
    finishTime(0),
    deltaTime(0),
    passedTime(0),
    fps(0),
    bombsNumber(10),
    score(0)
{
    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    vecDynamicObj.push_back(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(passedTime, fps, bombsNumber, score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY(); 
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    vecStaticObj.push_back(pGUI);

    Ground* pGr = new Ground;
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    vecStaticObj.push_back(pGr);

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(42, groundY - 1);
    vecStaticObj.push_back(pTank);

    TankAdapter* pTankAdapter = new TankAdapter;
    pTankAdapter->SetWidth(14);
    pTankAdapter->SetPos(10, groundY - 1);
    vecStaticObj.push_back(pTankAdapter);

    HouseDirector houseDirector(new HouseBuilder_B(new House));
    House* pHouse = houseDirector.getHouse();
    pHouse->SetWidth(13);
    pHouse->SetPos(55, groundY - 1);
    vecStaticObj.push_back(pHouse);

    houseDirector.setBuilder(new HouseBuilder_A(new House));
    pHouse = houseDirector.getHouse();
    pHouse->SetWidth(13);
    pHouse->SetPos(25, groundY - 1);
    vecStaticObj.push_back(pHouse);
}

SBomber::~SBomber()
{
    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            delete vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        if (vecStaticObj[i] != nullptr)
        {
            delete vecStaticObj[i];
        }
    }
}

void SBomber::MoveObjects()
{
    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Move(deltaTime);
        }
    }
};

void SBomber::CheckObjects()
{
    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked");

    collisionDetector.CheckPlaneAndLevelGUI(FindPlane(), FindLevelGUI(), exitFlag);
    collisionDetector.CheckBombsAndGround(vecDynamicObj, vecStaticObj, commandInterface, score);
};

Plane* SBomber::FindPlane() const
{
    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        Plane* p = dynamic_cast<Plane*>(vecDynamicObj[i]);        
        if (p != nullptr)
        {
            Logger::getInstance().write(typeid(vecDynamicObj[i]).name());            
            return p;
        }
    }

    return nullptr;
}

LevelGUI* SBomber::FindLevelGUI() const
{
    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        LevelGUI* p = dynamic_cast<LevelGUI*>(vecStaticObj[i]);
        if (p != nullptr)
        {
            Logger::getInstance().write(typeid(vecStaticObj[i]).name());
            return p;
        }
    }

    return nullptr;
}

void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        exitFlag = true;
        break;

    case 72: // up
        FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b': case 'B':
        commandInterface.Invoke(
            new DropBombCommand(FindPlane(), vecDynamicObj, new RealBomb, bombsNumber, score));
        break;

    case 'n':
        commandInterface.Invoke(
            new DropBombCommand(FindPlane(), vecDynamicObj, new BombDecorator(new RealBomb), bombsNumber, score));
        break;

    case 'v':
        commandInterface.Invoke(
            new DropBombCommand(FindPlane(), vecDynamicObj, 
                new BombDecorator(new BombDecorator(new RealBomb)), bombsNumber, score));
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        if (vecStaticObj[i] != nullptr)
        {
            vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    fps++;

    FindLevelGUI()->SetParam(passedTime, fps, bombsNumber, score);
}

void SBomber::TimeStart()
{
    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " was invoked");
    startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    finishTime = GetTickCount64();
    deltaTime = uint16_t(finishTime - startTime);
    passedTime += deltaTime;

    FileLoggerSingleton::getInstance().
        WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)deltaTime);
}