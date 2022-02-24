#include "Visitor.h"
#include "Bomb.h"
#include "Plane.h"
#include "Logger.cpp"

#include <sstream>

void LogVisitor::log(const Bomb& bomb) const {
	std::stringstream ss;
	ss << "Bomb: x " << bomb.GetX() << " y " << bomb.GetY() << " speed " << bomb.GetSpeed();
	auto direction = bomb.GetDirection();
	ss << " dx " << direction.first << " dy " << direction.second;
	Logger::getInstance().write(ss.str());
}

void LogVisitor::log(const Plane& plane) const {
	std::stringstream ss;
	ss << "Plane: x " << plane.GetX() << " y " << plane.GetY() << " speed " << plane.GetSpeed();
	auto direction = plane.GetDirection();
	ss << " dx " << direction.first << " dy " << direction.second;
	Logger::getInstance().write(ss.str());
}