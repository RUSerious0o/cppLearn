#pragma once

#include "GenericPlayer.cpp"

using namespace std;

class House : public GenericPlayer {
public:
	House(string name) : GenericPlayer(name) {}

	virtual bool isHitting() const override {
		if (getTotal() <= 16) return true;
		return false;
	}

	void flipFirstCard() {
		if (getTotal() == 0) return;
		flipCard(0);
	}
};