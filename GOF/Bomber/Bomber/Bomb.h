#pragma once

#include <vector>
#include <algorithm>

#include "DynamicObject.h"
#include "GameObject.h"
#include "Visitor.h"
#include "BombObservable.h"
#include "BombObserver.h"

class Bomb : public DynamicObject, public BombObservable {
public:
	virtual ~Bomb() {}

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	virtual void Draw() const {}

	virtual int getHeight() { return 0; }

	void __fastcall Accept(const Visitor& visitor) override {
		visitor.log(*this);
	}

	void AddObserver(BombObserver* observer) override {
		observers.push_back(observer);
	}

	void RemoveObserver(BombObserver* observer) override {
		auto it = std::find(observers.begin(), observers.end(), observer);
		if (it != observers.end()) {
			observers.erase(it);
		}
	}

	void Notify() override {
		for (BombObserver* observer : observers) {
			observer->HandleBombLanding(this);			
		}
	}	

	virtual Bomb* Clone() = 0;
protected:
	std::vector<BombObserver*> observers;
};

