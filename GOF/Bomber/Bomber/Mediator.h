#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <queue>

#include "LevelGUI.h"
#include "Tank.h"
#include "Logger.cpp"
#include "Tree.h"

class Mediator {
public:
	static Mediator& getInstance() {
		static Mediator instance;
		return instance;
	}

	void Subscribe(Tank* tank) {
		tanks.push_back(tank);
	}

	void Subscribe(std::shared_ptr<LevelGUI> gui) {
		this->gui = gui;
	}

	void Subscribe(Tree* tree) {
		trees.push_back(tree);
	}

	void Unsubscribe(Tank* tank) {
		auto it = std::find(tanks.begin(), tanks.end(), tank);
		if (it != tanks.end()) {
			tanks.erase(it);
		}
		Logger::getInstance().write("Tanks subscribed: ", static_cast<int>(tanks.size()));
	}

	const std::string GetMessage() {
		if (tanks.size() == 0) return "";

		if (messages.empty()) {
			RecieveMessages();
		}

		std::string msg = messages.front();
		messages.pop();
		return msg;
	}

	void GrowTrees() {
		for (Tree* tree : trees) {
			tree->Grow();
		}
	}

private:
	Mediator() {}
	Mediator(const Mediator& base) = delete;
	Mediator& operator=(const Mediator& base) = delete;

	std::vector<Tank*> tanks;
	std::shared_ptr<LevelGUI> gui;
	std::vector<Tree*> trees;

	std::queue<std::string> messages;

	void RecieveMessages() {
		for (Tank* tank : tanks) {
			messages.push(tank->GetMsg());
		}
	}
};

