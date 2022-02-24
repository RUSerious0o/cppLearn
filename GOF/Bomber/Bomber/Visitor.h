#pragma once

class Bomb;
class Plane;

class Visitor {
public:
	virtual void log(const Bomb& bomb) const {}
	virtual void log(const Plane& plane) const {}
};

class LogVisitor : public Visitor {
public:
	void log(const Bomb& bomb) const override;
	void log(const Plane& plane) const override;
};