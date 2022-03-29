#pragma once

#include <iostream>
#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

class RealBomb : public Bomb {
public:
    RealBomb() {}

	RealBomb(const RealBomb& base) {
		CopyFields(base);
	}

	RealBomb& operator=(const RealBomb& base) {
		CopyFields(base);
	}

	virtual void Draw() const override {
        MyTools::SetColor(CC_LightMagenta);
        GotoXY(x, y);
        cout << "*";
	}

    int getHeight() override { return 1; }

	RealBomb* Clone() override {
		return new RealBomb(*this);
	}

private:
	void CopyFields(const RealBomb& base) {
		x = base.x;
		y = base.y;
		width = base.width;
		speed = base.speed;
		xDirction = base.xDirction;
		yDirection = base.yDirection;

		for (BombObserver* observer : base.observers) {
			observers.push_back(observer);
		}
	}
};