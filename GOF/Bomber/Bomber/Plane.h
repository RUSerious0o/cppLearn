#pragma once

#include "DynamicObject.h"
#include "Visitor.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    void Accept(const Visitor& visitor) {
        visitor.log(*this);
    }

    void Accept(Visitor& visitor) {
        visitor.log(*this);
    }

    void Accept(const Visitor& visitor) const {
        visitor.log(*this);
    }

    void Accept(Visitor& visitor) const {
        visitor.log(*this);
    }
private:

};

