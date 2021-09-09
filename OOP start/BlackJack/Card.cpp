/*
4.	Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода: 
●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
#ifndef BJ_CARDS
#define BJ_CARDS

#include <ostream>
#include <sstream>

typedef enum Suit { Hearts = 0, Spades = 1, Clubs = 2, Diamonds = 3 } Suit;
typedef enum CardValue { 
	Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6,
	Seven = 7, Eight = 8, Nine = 9, Ten = 10,
	Jack = 11, Queen = 12, King = 13} CardValue;

class Card {
public:
	Card(CardValue value, Suit suit, bool stateOpen = true) :
		value(value), suit(suit), stateOpen(stateOpen) {}
	
	void flip() { stateOpen ^= 1; }
	
	int getValue() const {		
		return((int) value > 10 ? 10 : (int) value);
	}

	bool isOpen() const { return stateOpen; }

	friend ostream& operator<< (ostream&, const Card&);
private:
	Suit suit;
	CardValue value;
	bool stateOpen;

	string getFullName() const {
		stringstream result;
		if (suit == Hearts) result << "Ht";
		if (suit == Spades) result << "Sp";
		if (suit == Diamonds) result << "Dm";
		if (suit == Clubs) result << "Cl";

		result << "_";
		if (value == Ace) {
			result << "A";
			return result.str();
		}

		if (getValue() < 10) result << value;			
		else {
			if (value == Ten) result << "10";
			if (value == Jack) result << "J";
			if (value == Queen) result << "Q";
			if (value == King) result << "K";
		}
		return result.str();
	}
};

ostream& operator<< (ostream& out, const Card& card) {
	out << (card.isOpen() ? card.getFullName() : "XX");
	return out;
}

#endif