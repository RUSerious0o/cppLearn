#pragma once

#include <stdint.h>
#include <vector>

#include "GameObject.h"
#include "Observable.h"
#include "Observer.h"

class DestroyableGroundObject : public GameObject, public Observable {
public:

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

    virtual void AddObserver(Observer* observer) {
        observers.push_back(observer);
    }

    virtual void RemoveObserver(Observer* observer) {}

    virtual void Notify() {
        if (observers.size() > 0) {
            for (Observer* observer : observers) {
                observer->DestroyObject(this);
            }
        }
    }
protected:
    std::vector<Observer*> observers;
};