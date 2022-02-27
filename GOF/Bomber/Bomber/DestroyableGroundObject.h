#pragma once

#include <stdint.h>
#include <vector>

#include "GameObject.h"
#include "BombObserver.h"
#include "LandObjectObservable.h"
#include "LandObjectObserver.h"
#include "Bomb.h"

class DestroyableGroundObject : public GameObject, 
    public BombObserver, public LandObjectObservable {
public:

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

    virtual void AddObserver(LandObjectObserver* observer) override {
        observers.push_back(observer);
    }

    virtual void Notify() override {
        for (LandObjectObserver* observer : observers) {
            observer->DestroyObject(this);
        }
    }

    virtual void HandleBombLanding(Bomb* bomb) override {
        double x = bomb->GetX();
        double radius = bomb->GetWidth() / 2;
        double leftBorder = this->GetX() + 1;
        double rightBorder = this->GetX() + this->GetWidth() - 1;
        if ((x + radius > leftBorder) && (x + radius < rightBorder) ||
            (x - radius < rightBorder) && (x - radius > leftBorder)) {

            this->Notify();
        }
    }
protected:
    std::vector<LandObjectObserver*> observers;
};