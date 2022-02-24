#pragma once

#include <vector>

#include "DynamicObject.h"
#include "GameObject.h"
#include "Visitor.h"

class Bomb : public DynamicObject {
public:
	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	virtual void Draw() const {}

	virtual int getHeight() { return 0; }

	void __fastcall Accept(const Visitor& visitor) override {
		visitor.log(*this);
	}

};

