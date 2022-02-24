#pragma once

#include "BombObserver.h"

class BombObservable {
public:
	virtual void AddObserver(BombObserver& observer) = 0;
	virtual void RemoveObserver(BombObserver& observer) = 0;
	virtual void Notify() = 0;
};

