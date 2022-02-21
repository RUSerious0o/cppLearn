#pragma once

#include <iostream>
#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

class RealBomb : public Bomb {
	virtual void Draw() const override {
        MyTools::SetColor(CC_LightMagenta);
        GotoXY(x, y);
        cout << "*";
	}

    int getHeight() override { return 1; }
};