#pragma once

#include "Observer.h"

class Observable {
public:
	virtual void AddObserver(Observer* observer) = 0;
	virtual void RemoveObserver(Observer* observer) = 0;
	virtual void Notify() = 0;
};

