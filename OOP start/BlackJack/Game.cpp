#pragma once

#include "Card.cpp"
#include "Player.cpp"
#include "House.cpp"
#include "Deck.cpp"

using namespace std;

class Game {
public:
	Game(vector<string> names) : house(House(HOUSE_NAME)) {
		for (string name : names)
			players.push_back(Player(name));

		deck.shuffle();
	}

	void play() {
		for (Player &player : players) {
			deck.deal(player).deal(player);			
		}
		
		deck.deal(house).deal(house);		
		house.flipFirstCard();

		for (Player& player : players) {
			printTurn();
			deck.additionalCards(player);
		}
		
		house.flipFirstCard();
		printTurn();
		deck.additionalCards(house);

		printTurn(true);

		for (Player& player : players)
			player.clear();
		house.clear();
		deck.clear();
	}

	
private:
	const string HOUSE_NAME = "Dealer";

	Deck deck;
	House house;
	vector<Player> players;

	void printTurn(bool printWinStates = false) {
		system("cls");
		cout << house << "\n\n";

		for (Player& player : players) {
			cout << player;

			if (printWinStates) {
				if (player.isBoosted()) cout << " LOSE!";
				else if (house.isBoosted()) cout << " WIN!";
				else if (player.getTotal() > house.getTotal()) cout << " WIN!";
				else if (player.getTotal() == house.getTotal()) cout << " DRAW!";
				else if (player.getTotal() < house.getTotal()) cout << " LOSE!";
			}

			cout << endl;
		}			
		cout << endl;
	}
};