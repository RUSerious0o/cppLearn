#pragma once

#include <vector>

#include "DynamicObject.h"
#include "LevelGUI.h"
#include "Bomb.h"
#include "Commands.h"
#include "House.h"
#include "Tank.h"
#include "Ground.h"
#include "BombIterator.h"

class CollisionDetector {
public:
    virtual void CheckPlaneAndLevelGUI(DynamicObject* plane, LevelGUI* gui, bool& exitFlag) = 0;

    virtual ~CollisionDetector() = default;
};

class BaseCollisionDetector : public CollisionDetector {
public:
    void CheckPlaneAndLevelGUI(DynamicObject* plane, LevelGUI* gui, bool& exitFlag) override {
        if(plane->GetX() > gui->GetFinishX()) {
            exitFlag = true;
        }
    }

};