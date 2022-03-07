#pragma once

#include <memory>

#include "LandObjectObserver.h"
#include "BombObserver.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Ground.h"
#include "Commands.h"
#include "CollisionDetector.h"

class SBomberImpl : public LandObjectObserver, public BombObserver {
public:
    SBomberImpl();
    ~SBomberImpl();

    bool GetExitFlag() const;

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

