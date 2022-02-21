#pragma once

#include "DynamicObject.h"
#include "GameObject.h"
#include "LoggerSingleton.cpp"
#include "RealBomb.h"
#include "Plane.h"
#include "Ground.h"

#include <vector>

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() {}
};

class DeleteDynamicObjCommand : public Command {
public:
    DeleteDynamicObjCommand(DynamicObject* obj, std::vector<DynamicObject*>& objects) :
    obj(obj), objects(objects) {}

    void Execute() override {
        auto it = objects.begin();
        for (; it != objects.end(); it++)
        {
            if (*it == obj)
            {
                auto temp = it;                
                objects.erase(it);
                //delete *temp;         // throws error

                break;
            }
        }
    }
private:
    DynamicObject* obj;
    std::vector<DynamicObject*>& objects;
};

class DeleteStaticObjCommand : public Command {
public:
    DeleteStaticObjCommand(GameObject* obj, std::vector<GameObject*>& objects) :
        obj(obj), objects(objects) {}

    void Execute() override {
        auto it = objects.begin();
        for (; it != objects.end(); it++)
        {
            if (*it == obj)
            {
                auto temp = it;
                objects.erase(it);
                //delete *temp;

                break;
            }
        }        
    }
private:
    GameObject* obj;
    std::vector<GameObject*>& objects;
};

class DropBombCommand : public Command {
public:
    DropBombCommand(const Plane* plane, std::vector<DynamicObject*>& objects, DynamicObject* bomb,
        uint16_t& bombsCount, int16_t& score,
        double speed = 2.0, CraterSize craterSize = SMALL_CRATER_SIZE) :
        plane(plane), objects(objects), bomb(bomb),
        bombsCount(bombsCount), score(score),
        speed(speed), craterSize(craterSize) {}

    void Execute() override {
        if (bombsCount > 0)
        {
            FileLoggerSingleton::getInstance().
                WriteToLog(string(__FUNCTION__) + " was invoked");

            double x = plane->GetX() + 4;
            double y = plane->GetY() + 2;

            bomb->SetDirection(0.3, 1);
            bomb->SetSpeed(speed);
            bomb->SetPos(x, y);
            bomb->SetWidth(craterSize);

            objects.push_back(bomb);
            bombsCount--;
            score -= Bomb::BombCost;
        }
    }
private:
    const Plane* plane;
    std::vector<DynamicObject*>& objects;
    uint16_t& bombsCount;
    int16_t& score;
    double speed;
    CraterSize craterSize;
    DynamicObject* bomb;
};

class DropDecoratedBomd : public Command {

};

class CommandInterface {
public:
    void Invoke(Command* command) {        
        command->Execute();
        delete command;
    }
};