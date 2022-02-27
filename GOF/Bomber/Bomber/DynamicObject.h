#pragma once

#include <stdint.h>
#include <sstream>
#include <utility>

#include "GameObject.h"
#include "Visitor.h"
#include "Logger.cpp"

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    virtual inline void SetSpeed(double sp) { speed = sp; }
    virtual inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    virtual inline double GetSpeed() const { return speed; }
    virtual inline std::pair<double, double> GetDirection() const { 
        return std::pair<double, double>(xDirction, yDirection);
    }

    virtual void __fastcall Accept(const Visitor& visitor) {}
protected:

    double speed;
    double xDirction, yDirection;

};
