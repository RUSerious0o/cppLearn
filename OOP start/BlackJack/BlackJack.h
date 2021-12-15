#include <stack>
#include <vector>

class Card {
	Card(std::string suit, std::string value) : 
		suit(suit), value(value) { setWeight(); }	
	
private:
	std::string suit;
	std::string value;
	int weight;
	
	void setWeight();
};

class Deck {
	Deck(int decksNum) { generateDeck(decksNum); }
	
private:
	generateDeck(int decksNum);
	std::stack<Card> cards;
};

class Hand {
public:
	void addCard(Card card);
	int countWeight();
	void reset();
private:
	std::vector<Card> cards;
};

class Chip {
	
};

class Pocket {
public:	
	bool addChip(Chip chip) { 
		chips.push_back(chip); 
		return true;
	}
	
	std::vector<Chip> getChips(int volume);
	
	int countChips();
private:
	std::vector<Chip> chips;
};

class BJPerson {
	void makeBet(int volume);
	void hitMe();
	void enough();
private:
	Hand hand;
	Pocket pocket;
};

class Dealer : public BJPerson {
	
};

class AI : public BJPerson {
	
};

class Player : public BJPerson {
	
};

class Game {
public:
	void init(); //	вероятнее всего будет реализована в конструкторе
	void startRound();
	void dealCards();
	void handOverCard();
	void playerTurn();
	void printTable();
	void finishRound();
	void resetGame();
	void endGame();
private:
	Deck deck;
	Player player;
	Dealer dealer;
	std::vector<AI> ai;
	double shufflePoint;	// когда (0...1) перемешиваем колоду
	
	void initPerson(int pocketValue);
	void setShufflePoint(double shufflePoint);
};

