#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
private:
	static const uint16_t HOUSE_HEIGHT = 7;
	static const uint16_t ROOF_HEIGHT = 3;
	static const uint16_t HOUSE_WIDTH = 14;
	static const uint16_t WINDOW_HEIGHT= 3;
	static const uint16_t WINDOW_WIDTH = 6;
	static const uint16_t CHIMNEY_HEIGHT = 3;
	static const uint16_t CHIMNEY_POSITION = 10;

	const uint16_t score = 40;
	char look[HOUSE_HEIGHT][HOUSE_WIDTH];

public:
	House();

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void buildWalls(int argc, ...);
	void buildRoof(char roof[ROOF_HEIGHT][HOUSE_WIDTH]);
	void buildWindow(char window[WINDOW_HEIGHT][WINDOW_WIDTH]);
	void buildChimney(char chimney[CHIMNEY_HEIGHT]);
};

