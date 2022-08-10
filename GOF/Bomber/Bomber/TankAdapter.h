#pragma once

#include <iostream>

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"
#include "MyTools.h"
#include "Tank.h"
#include "Logger.cpp"

class TankAdapter : public Tank {
public:
    inline void SetPos(double nx, double ny) override {
		// x, y are needed for methods draw() && inInside() implementation
		x = nx;
		y = ny;
		adaptee.SetPos(nx, ny); 
	}

	inline double GetY() const override { 
		return adaptee.GetY(); 
	}

	inline double GetX() const override { 
		return adaptee.GetX(); 
	}

	inline void SetWidth(uint16_t widthN) override { 
		adaptee.SetWidth(widthN); 
	}

	inline uint16_t GetWidth() const override { 
		return adaptee.GetWidth(); 
	}

	inline uint16_t GetScore() const override { 
		return adaptee.GetScore(); 
	}

	void Draw() const override {
		// no link to adaptee.Paint() cause that method isn`t implemented
		MyTools::SetColor(MyTools::CC_Red);
		MyTools::GotoXY(x, y - 3);
		std::cout << "    ######";
		MyTools::GotoXY(x - 2, y - 2);
		std::cout << "  #####    #";
		MyTools::GotoXY(x, y - 1);
		std::cout << "    ######";
		MyTools::GotoXY(x, y);
		std::cout << " ############";
	}

	bool __fastcall isInside(double x1, double x2) const override {		
		const double XBeg = x + 2;
		// implemantation differs from Tank.inInside() only with this:
		const double XEnd = x + adaptee.GetWidth() - 1;

		if (x1 < XBeg && x2 > XEnd) {
			return true;
		}

		if (x1 > XBeg && x1 < XEnd) {			
			return true;
		}

		if (x2 > XBeg && x2 < XEnd) {			
			return true;
		}

		return false;		
	}
private:
	double x, y;
	TankAdaptee adaptee;
};

