#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:
	static const uint16_t BombCost = 10; // ��������� ����� � �����

	virtual void Draw() const {}

	virtual int getHeight() { return 0; }
private:

};

