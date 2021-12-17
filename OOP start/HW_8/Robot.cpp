#pragma once

#include <iostream>
#include "RobotError.cpp"

using namespace std;

class Robot {
public:
	Robot(int width = DEFAULT_SIZE, int height = DEFAULT_SIZE) : width(width), height(height) {
		field = (POSITION_VALUE**)malloc(sizeof(POSITION_VALUE*) * height);
		for (int i = 0; i < height; i++) {
			field[i] = (POSITION_VALUE*)malloc(sizeof(POSITION_VALUE) * width);

			for (int j = 0; j < width; j++)
				field[i][j] = BLANK;
		}
	}

	virtual ~Robot() {
		for (int i = 0; i < width; i++) {
			free(field[i]);
		}
		free(field);
	}

	void print() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				printf("%c|", field[i][j]);
			cout << endl;
		}

		cout << "Available commands:\n";
		cout << "7 8 9\n4   6\n1 2 3\n";
	}

	void place(int x, int y) {
		checkPosition(x, y);

		if (robotPositionIsSet)
			throw IllegalCommand("Robot is already on the field!");

		positionX = x;
		positionY = y;
		field[y][x] = ROBOT;
		robotPositionIsSet = true;
	}

	void move() {
		int command, dx, dy;
		cin >> command;
		if (command == 1) {
			dx = -1;
			dy = 1;
		}
		else if (command == 2) {
			dx = 0;
			dy = 1;
		}
		else if (command == 3) {
			dx = 1;
			dy = 1;
		}
		else if (command == 4) {
			dx = -1;
			dy = 0;
		}
		else if (command == 6) {
			dx = 1;
			dy = 0;
		}
		else if (command == 7) {
			dx = -1;
			dy = -1;
		}
		else if (command == 8) {
			dx = 0;
			dy = -1;
		}
		else if (command == 9) {
			dx = 1;
			dy = -1;
		}
		else throw IllegalCommand("Illegal command!");

		checkPosition(positionX + dx, positionY + dy);
		field[positionY][positionX] = VISITED;
		field[positionY + dy][positionX + dx] = ROBOT;
		positionX += dx;
		positionY += dy;
	}

	void checkPosition(int x, int y) {
		if (x < 0 || x >= width || y < 0 || y >= height)
			throw OffTheField(positionX, positionY, x, y);
		if (field[y][x] == VISITED)
			throw IllegalCommand("Requested position is already visited!");
	}
private:
	enum POSITION_VALUE { ROBOT = 'o', BLANK = '_', VISITED = 'X' };

	static const int DEFAULT_SIZE = 10;
	int width, height;
	POSITION_VALUE** field;
	int positionX, positionY;
	bool robotPositionIsSet = false;
};