#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

#include "Commands.h"
#include "BombIterator.h"
#include "CollisionDetector.h"
#include "Visitor.h"
#include "LandObjectObserver.h"

class SBomber : public LandObjectObserver {
public:
    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();
    
    void DestroyObject(DestroyableGroundObject* object, Bomb* bomb) override;

private:
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    Ground* FindGround(std::vector<GameObject*>& vecStaticObj) const;

    void CheckBombLanding();    

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    CommandInterface commandInterface;
    BaseCollisionDetector collisionDetector;
    LogVisitor logVisitor;
};