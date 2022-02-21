#pragma once

#include <memory>

#include "House.h"

class HouseBuilder {
public:
	HouseBuilder(House * house) : house(house) {}
	virtual ~HouseBuilder() = default;

	House* getHouse() { return house; }

	virtual void buildHouse() {
		buildWalls();
		buildRoof();
		buildWindow();
		buildChimney();
	}

protected:
	House* house;

	virtual void buildWalls() {}
	virtual void buildRoof() {}
	virtual void buildChimney() {}
	virtual void buildWindow() {}
};

class HouseBuilder_A : public HouseBuilder {
public:
	HouseBuilder_A(House* house) : HouseBuilder(house) {}

private:
	void buildWalls() override {
		house->buildWalls(7, '#', '#', '#', '#', '#', ' ', ' ');		
	}

	void buildRoof() override {
		char roof[3][14]{
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' '},
			{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}
		};
		house->buildRoof(roof);
	}

	void buildChimney() override {
		char chimney[3]{ ' ', '#', '#' };
		house->buildChimney(chimney);
	}

	void buildWindow() override {
		char window[3][6]{
			{ ' ', '#', '#', '#', '#', ' ' },
			{ ' ', '#', ' ', ' ', '#', ' ' },
			{ ' ', '#', '#', '#', '#', ' ' }
		};
		house->buildWindow(window);
	}
};

class HouseBuilder_B : public HouseBuilder {
public:
	HouseBuilder_B(House* house) : HouseBuilder(house) {}

private:
	void buildWalls() override {
		house->buildWalls(7, '#', '#', '#', '#', ' ', ' ', ' ');
	}

	void buildRoof() override {
		char roof[3][14]{
			{' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' '},
			{' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' '},
			{'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'}
		};
		house->buildRoof(roof);
	}

	void buildWindow() override {
		char window[3][6]{
			{ '#', '#', '#', '#', '#', '#' },
			{ '#', ' ', '|', '|', ' ', '#' },
			{ '#', '#', '#', '#', '#', '#' }
		};
		house->buildWindow(window);
	}
};