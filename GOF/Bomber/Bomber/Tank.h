#pragma once

#include <stdint.h>
#include <iostream>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
	Tank();

	virtual ~Tank();

	virtual bool __fastcall isInside(double x1, double x2) const override;

	virtual inline uint16_t GetScore() const override { return score; }

	virtual void Draw() const override;

	std::string GetMsg();
private:
	const uint16_t score = 30;	
	static const std::vector<std::string> phrases;
};

