#pragma once

#include <vector>
#include <memory>

#include "DynamicObject.h"
#include "GameObject.h"
#include "RealBomb.h"
#include "Plane.h"
#include "Ground.h"
#include "House.h"
#include "Tank.h"
#include "DestroyableGroundObject.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() {}
};

class DeleteBombCommand : public Command {
public:
    DeleteBombCommand(Bomb* bomb, std::vector<Bomb*>& bombs) :
    obj(bomb), objects(bombs) {}

    void Execute() override;
private:
    Bomb* obj;
    std::vector<Bomb*>& objects;
};

class DeleteStaticObjCommand : public Command {
public:
    DeleteStaticObjCommand(DestroyableGroundObject* obj,
        std::vector<DestroyableGroundObject*>& objects) :
        obj(obj), objects(objects) {}

    void Execute() override;
private:
    DestroyableGroundObject* obj;
    std::vector<DestroyableGroundObject*>& objects;
};

class DropBombCommand : public Command {
public:
    DropBombCommand(std::shared_ptr<Plane> plane, Bomb* bomb,
        double speed = DEFAULT_SPEED, uint16_t craterSise = SMALL_CRATER_SIZE) :
        plane(plane), bomb(bomb), speed(speed), craterSize(craterSize) {}

    void Execute() override;

private:
    const int X_OFFSET = 4;
    const int Y_OFFSET = 2;
    const double X_DIRECTION = 0.3;
    const double Y_DIRECTION = 1.0;

    static const double DEFAULT_SPEED;

    std::shared_ptr<Plane> plane;
    double speed;
    CraterSize craterSize;
    Bomb* bomb;
};

class CommandInterface {
public:
    void Invoke(Command* command) {        
        command->Execute();
        delete command;
    }
};