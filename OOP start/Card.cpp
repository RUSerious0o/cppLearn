/*
4.	Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода: 
●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
#ifndef BJ_CARDS
#define BJ_CARDS

typedef enum Suit { Hearts = 0, Spades = 1, Clubs = 2, Diamonds = 3 } Suit;
typedef enum CardValue { 
	Two = 2, Three = 3, Four = 4, Five = 5, Six = 6,
	Seven = 7, Eight = 8, Nine = 9, Ten = 10,
	Jack = 11, Queen = 12, King = 13, Ace = 14} CardValue;

class Card {
public:
	Card(CardValue value, Suit suit, bool stateOpen) :
		value(value), suit(suit), stateOpen(stateOpen) {}
	
	void flip() { stateOpen ^= 1; }
	
	int getValue() {
		if(value == Ace) return 1;
		return((int) value > 10 ? 10 : (int) value);
	}
	
	bool getState() { return stateOpen; }
private:
	Suit suit;
	CardValue value;
	bool stateOpen;
};

#endif