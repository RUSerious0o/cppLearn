#pragma once

#include <vector>
#include <memory>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "DestroyableGroundObject.h"

#include "Commands.h"
#include "BombIterator.h"
#include "CollisionDetector.h"
#include "Visitor.h"
#include "LandObjectObserver.h"


class SBomber : public LandObjectObserver, public BombObserver {
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
    
    void DestroyObject(DestroyableGroundObject* object) override;
    void HandleBombLanding(Bomb* bomb) override;

private:
    void CheckBombLanding();    
    void DrawMacroObjects();

    void ProcessBomb(Bomb* bomb);

    std::shared_ptr<Plane> plane;
    std::shared_ptr<LevelGUI> levelGUI;
    std::shared_ptr<Ground> ground;

    std::vector<Bomb*> bombs;
    std::vector<DestroyableGroundObject*> groundObjects;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsCount, deltaTime, fps;
    int16_t score;

    CommandInterface commandInterface;
    BaseCollisionDetector collisionDetector;
    LogVisitor logVisitor;
};