#pragma once

#include "Bomb.h"
#include "Plane.h"

class Visitor {
public:
	void log(const Bomb& bomb) {}
	void log(const Plane& plane) {}
	void log(const Bomb& bomb) const {}
	void log(const Plane& plane) const {}
};