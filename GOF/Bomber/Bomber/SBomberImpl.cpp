#include "SBomberImpl.h"

#include <conio.h>
#include <windows.h>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "MyTools.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "TankAdapter.h"

#include "Logger.cpp"
#include "Commands.h"
#include "BombDecorator.h"
#include "RealBomb.h"
#include "HouseDirector.h"
#include "CollisionDetector.h"
#include "ColorPlane.h"
#include "BigPlane.h"
#include "Mediator.h"
#include "Tree.h"

using namespace std;
using namespace MyTools;

SBomberImpl::SBomberImpl()
    : exitFlag(false),
    startTime(0),
    finishTime(0),
    deltaTime(0),
    passedTime(0),
    fps(0),
    bombsCount(10),
    score(0)
{
    srand(time(0));
    if (int rnd = rand() % 2 == 0) {
        plane = std::shared_ptr<Plane>(new ColorPlane);
    }
    else {
        plane = std::shared_ptr<Plane>(new BigPlane);
    }
    plane->SetDirection(1, 0.1);
    plane->SetSpeed(4);
    plane->SetPos(5, 10);

    levelGUI = std::shared_ptr<LevelGUI>(new LevelGUI);
    levelGUI->SetParam(passedTime, fps, bombsCount, score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY();
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    levelGUI->SetPos(offset, offset);
    levelGUI->SetWidth(width);
    levelGUI->SetHeight(maxY - 4);
    levelGUI->SetFinishX(offset + width - 4);
    Mediator::getInstance().Subscribe(levelGUI);

    ground = std::shared_ptr<Ground>(new Ground);
    const uint16_t groundY = GetMaxY() - 5;
    ground->SetPos(offset + 1, groundY);
    ground->SetWidth(width - 2);
    //_________________________________________________________________

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(42, groundY - 1);
    groundObjects.push_back(pTank);
    pTank->AddObserver(this);
    Mediator::getInstance().Subscribe(pTank);

    TankAdapter* pTankAdapter = new TankAdapter;
    pTankAdapter->SetWidth(14);
    pTankAdapter->SetPos(10, groundY - 1);
    groundObjects.push_back(pTankAdapter);
    pTankAdapter->AddObserver(this);
    Mediator::getInstance().Subscribe(pTankAdapter);

    HouseDirector houseDirector(new HouseBuilder_B(new House));
    House* pHouse = houseDirector.getHouse();
    pHouse->SetWidth(13);
    pHouse->SetPos(55, groundY - 1);
    groundObjects.push_back(pHouse);
    pHouse->AddObserver(this);

    houseDirector.setBuilder(new HouseBuilder_A(new House));
    pHouse = houseDirector.getHouse();
    pHouse->SetWidth(13);
    pHouse->SetPos(25, groundY - 1);
    groundObjects.push_back(pHouse);
    pHouse->AddObserver(this);

    Tree* tree = new Tree;
    tree->SetWidth(5);
    tree->SetPos(4, groundY - 1);
    groundObjects.push_back(tree);
    Mediator::getInstance().Subscribe(tree);
}

SBomberImpl::~SBomberImpl() {
    for (size_t i = 0; i < bombs.size(); i++) {
        if (bombs[i] != nullptr) {
            delete bombs[i];
        }
    }

    for (size_t i = 0; i < groundObjects.size(); i++) {
        if (groundObjects[i] != nullptr) {
            delete groundObjects[i];
        }
    }
}

bool SBomberImpl::GetExitFlag() const {
    return exitFlag;
}

void SBomberImpl::MoveObjects()
{
    plane->Move(deltaTime);
    plane->Accept(logVisitor);

    for (size_t i = 0; i < bombs.size(); ++i) {
        if (bombs[i] != nullptr) {
            bombs[i]->Move(deltaTime);
            bombs[i]->Accept(logVisitor);
        }
    }
};

void SBomberImpl::CheckObjects()
{
    collisionDetector.CheckPlaneAndLevelGUI(plane, levelGUI, exitFlag);
    CheckBombLanding();
    levelGUI->CheckTankMessage();
    levelGUI->CheckTrees();
};

void SBomberImpl::CheckBombLanding() {
    for (Bomb* bomb : bombs) {
        if (bomb != nullptr) {
            if (bomb->GetY() >= ground->GetY()) {
                // if observers added when bomb "dropped", throws error when object
                // destroyed while another bomb is in air
                for (DestroyableGroundObject* object : groundObjects) {
                    bomb->AddObserver(object);
                }
                bomb->Notify();
            }
        }
    }
}

void SBomberImpl::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    switch (c) {

    case 27: // esc
        exitFlag = true;
        break;

    case 72: // up
        plane->ChangePlaneY(-0.25);
        break;

    case 80: // down
        plane->ChangePlaneY(0.25);
        break;

    case 'b': case 'B':
        if (bombsCount > 0) {
            Bomb* bomb = new RealBomb;
            ProcessBomb(bomb);
        }

        break;

    case 'n':
        if (bombsCount > 0) {
            Bomb* bomb = new BombDecorator(new RealBomb);
            ProcessBomb(bomb);
        }

        break;

    case 'v':
        if (bombsCount > 0) {
            Bomb* bomb = new BombDecorator(new BombDecorator(new RealBomb));
            ProcessBomb(bomb);
        }

        break;

    default:
        break;
    }
}

void SBomberImpl::ProcessBomb(Bomb* bomb) {
    bombs.push_back(bomb);
    bombsCount--;
    score -= Bomb::BombCost;

    bomb->AddObserver(this);

    commandInterface.Invoke(new DropBombCommand(plane, bomb));
}

void SBomberImpl::DrawFrame() {
    DrawMacroObjects();

    for (size_t i = 0; i < bombs.size(); i++) {
        if (bombs[i] != nullptr) {
            bombs[i]->Draw();
        }
    }

    for (size_t i = 0; i < groundObjects.size(); i++) {
        if (groundObjects[i] != nullptr) {
            groundObjects[i]->Draw();
        }
    }

    GotoXY(0, 0);
    fps++;

    levelGUI->SetParam(passedTime, fps, bombsCount, score);
}

void SBomberImpl::DrawMacroObjects() {
    plane->Draw();
    levelGUI->Draw();
    ground->Draw();
}

void SBomberImpl::TimeStart() {
    startTime = GetTickCount64();
}

void SBomberImpl::TimeFinish() {
    finishTime = GetTickCount64();
    deltaTime = uint16_t(finishTime - startTime);
    passedTime += deltaTime;
}

void SBomberImpl::DestroyObject(DestroyableGroundObject* object) {
    score += object->GetScore();

    commandInterface.Invoke(
        new DeleteStaticObjCommand(object, groundObjects));
}

void SBomberImpl::HandleBombLanding(Bomb* bomb) {
    ground->AddCrater(bomb->GetX());
    commandInterface.Invoke(
        new DeleteBombCommand(bomb, bombs));
}