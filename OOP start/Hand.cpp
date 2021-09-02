#include <vector>
#include "Card.cpp"

using namespace std;

class Hand {
public:
	void add(Card*);
	void clear();
	int getValue();
	
private:
	vector<Card*> cards;
};

void Hand::add(Card* card) {
	cards.push_back(card);
}

void Hand::clear() {
	for(int i = cards.size() - 1; i >= 0; i--) {
		delete cards[i];
		cards.pop_back();
	}
}

// два туза - блэк-джек. Пока считаем только сумму очков
int Hand::getValue() {
	if(cards.size() == 2 && cards[0]->getValue() == 1 && cards[1]->getValue() == 1) {		
		return 21;
	}
	
	int sum = 0, acesCount = 0;
	int cardValue;
	for(int i = 0; i < cards.size(); i++) {
		cardValue = cards[i]->getValue();
		
		if(cardValue == 1) {
			acesCount++;
			cardValue = 11;
		} 
		
		sum += cardValue;
		if(sum > 21 && acesCount > 0) {
			sum -= 10;
			acesCount--;
		}		
	}
	
	return sum;
}