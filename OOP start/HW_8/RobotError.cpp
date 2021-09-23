#pragma once
#include <iostream>

using namespace std;

class RobotError {
public:
	virtual void print(ostream& where) const = 0;
};

class OffTheField : public RobotError {
public:
	OffTheField(int currentX, int currentY, int targetX, int targetY) :
		currentX(currentX), currentY(currentY), targetX(targetX), targetY(targetY) {
	}

	virtual void print(ostream& where) const override {
		where << "Trying to move off the field, from x: " << currentX << ", y: " << currentY
			<< " to x: " << targetX << ", y: " << targetY;
	}
private:
	int currentX, currentY, targetX, targetY;
};

class IllegalCommand : public RobotError {
public:
	IllegalCommand(const string& msg) : msg(msg) {}

	virtual void print(ostream& where) const override {
		where << msg;
	}
private:
	string msg;
};

ostream& operator<< (ostream& out, const RobotError& err) {
	err.print(out);
	return out;
}