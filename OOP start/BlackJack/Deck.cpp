#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include "Hand.cpp"

class Deck : public Hand {
public:
	Deck() : Hand() {
		srand(time(0));
		populate();
	}
	
	void shuffle() {
		for (int i = 0; i < SHUFFLE_SWAPS_COUNT; i++)
			swapPair();
	}

	Deck& deal(Hand& hand) {
		hand.add(cards.back());
		cards.pop_back();
		return *this;
	}

	void additionalCards(GenericPlayer &player) {
		printPlayerInfo(player);
		while (!(player.isBoosted() || player.getTotal() == 21) && player.isHitting()) {
			deal(player);
			cout << player << endl;
			printPlayerInfo(player);
		}
	}
private:
	static const int CARDS_COUNT = 52;
	static const int SHUFFLE_SWAPS_COUNT = CARDS_COUNT * 16;

	void populate() {
		for (Suit suit : vector<Suit>{Hearts, Spades, Diamonds, Clubs}) {
			for (CardValue value : vector<CardValue>{
					Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
					Jack, Queen, King }) {
				cards.push_back(new Card(value, suit, true));
			}
		}
	}

	void swapPair() {
		int firstCard = rand() % CARDS_COUNT, secondCard;
		do {
			secondCard = rand() % CARDS_COUNT;
		} while (firstCard == secondCard);
		swap(cards[firstCard], cards[secondCard]);
	}

	void printPlayerInfo(const GenericPlayer &player) const {
		cout << player.getName() << " turn. Total is: " << player.getTotal() << ". ";
	}
};