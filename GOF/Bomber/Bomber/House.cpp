
#include <iostream>
#include <stdarg.h>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

House::House() {
	for (int i = 0; i < HOUSE_HEIGHT; ++i) {
		for (int j = 0; j < HOUSE_WIDTH; ++j) {
			look[i][j] = ' ';
		}
	}
}

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);	
	for (int i = 0; i < HOUSE_HEIGHT; ++i) {
		GotoXY(x, y - i);
		for (int j = 0; j < HOUSE_WIDTH; ++j) {
			std::cout << look[i][j];
		}
		std::cout << std::endl;
	}
}

void House::buildWalls(int argc, ...) {
	if (argc <= 0) return;

	va_list args;
	va_start(args, argc);

	for (int i = 0; i < argc; ++i) {
		if (i == HOUSE_HEIGHT) break;		
		look[i][0] = look[i][HOUSE_WIDTH - 1] = va_arg(args, char);
	}

	va_end(args);

	for (int i = 1; i < HOUSE_WIDTH - 1; ++i) {
		look[0][i] = '#';
	}
}

void House::buildRoof(char roof[ROOF_HEIGHT][HOUSE_WIDTH]) {
	for (int i = 0; i < ROOF_HEIGHT; ++i) {
		for (int j = 0; j < HOUSE_WIDTH; ++j) {
			look[HOUSE_HEIGHT - 1 - i][j] = roof[i][j];
		}
	}
}

void House::buildWindow(char window[WINDOW_HEIGHT][WINDOW_WIDTH]) {
	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
		for (int j = 0; j < WINDOW_WIDTH; ++j) {
			look[1 + i][HOUSE_WIDTH / 2 - WINDOW_WIDTH / 2 + j] = window[i][j];
		}
	}
}

void House::buildChimney(char chimney[CHIMNEY_HEIGHT]) {
	for (int i = 0; i < CHIMNEY_HEIGHT; ++i) {
		look[HOUSE_HEIGHT - CHIMNEY_HEIGHT + i][CHIMNEY_POSITION] = chimney[i];
	}
}