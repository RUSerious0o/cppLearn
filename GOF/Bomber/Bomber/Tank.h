#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	virtual bool __fastcall isInside(double x1, double x2) const override;

	virtual inline uint16_t GetScore() const override { return score; }

	virtual void Draw() const override;

private:

	const uint16_t score = 30;
};
