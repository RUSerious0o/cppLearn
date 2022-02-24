#pragma once

#include <vector>

#include "DynamicObject.h"
#include "GameObject.h"
#include "Visitor.h"
#include "BombObservable.h"

class Bomb : public DynamicObject, public BombObservable {
public:
	static const uint16_t BombCost = 10; // ��������� ����� � �����

	virtual void Draw() const {}

	virtual int getHeight() { return 0; }

	void __fastcall Accept(const Visitor& visitor) override {
		visitor.log(*this);
	}

	void AddObserver(BombObserver& observer) override {
		observers.push_back(observer);
	}

	void RemoveObserver(BombObserver& observer) override {}

	void Notify() override {

	}

protected:
	std::vector<BombObserver> observers;
};
