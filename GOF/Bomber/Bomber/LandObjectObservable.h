#pragma once

#include "LandObjectObserver.h"

class LandObjectObservable {
public:
	virtual void AddObserver(LandObjectObserver* observer) = 0;
	virtual void Notify() = 0;
};

