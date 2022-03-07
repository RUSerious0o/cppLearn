#pragma once
#include "Plane.h"
class BigPlane : public Plane {
protected:
    void DrawBody() const override;
    void DrawWings() const override;
    void DrawTail() const override;
};

