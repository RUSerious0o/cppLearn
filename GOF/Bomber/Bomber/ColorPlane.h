#pragma once
#include "Plane.h"

class ColorPlane : public Plane {
protected:
    void DrawBody() const override;
    void DrawWings() const override;
    void DrawTail() const override;
};

