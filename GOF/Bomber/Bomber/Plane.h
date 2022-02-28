#pragma once

#include "DynamicObject.h"
#include "Visitor.h"
#include "MyTools.h"

class Plane : public DynamicObject {
public:

    virtual void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    void __fastcall Accept(const Visitor& visitor) override {
        visitor.log(*this);
    }

protected:
    virtual void SetColor(MyTools::ConsoleColor color) const;
    virtual void DrawBody() const;
    virtual void DrawWings() const;
    virtual void DrawTail() const;
};

