#pragma once

#include <vector>

#include "DynamicObject.h"
#include "Bomb.h"

class BombIterator {
public:
	BombIterator(const std::vector<DynamicObject*>& objects) : objects(objects), 
		currentIndex(-1) {}

	DynamicObject* operator*() {
		if (currentIndex == -1) return nullptr;
		return objects.at(currentIndex);
	}

	BombIterator& next() {
		if (objects.size() == 0) return *this;

		++currentIndex;		

		Bomb* bomb;
		for (; currentIndex < objects.size(); ++currentIndex) {
			bomb = dynamic_cast<Bomb*>(objects[currentIndex]);
			if (bomb != nullptr) {
				return *this;
			}
		}

		currentIndex = -1;
		return *this;
	}
private:
	const std::vector<DynamicObject*>& objects;
	size_t currentIndex;
};