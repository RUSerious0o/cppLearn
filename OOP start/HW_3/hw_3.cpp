#include <iostream>
#include <vector>
#include "Figures.cpp"
#include "Car.cpp"
#include "Fraction.cpp"
#include "../BlackJack/Card.cpp"

using namespace std;

int main() {
	system("cls");
	// 3.1
	vector<Figure*> figures;
	figures.push_back(new Parallelogram(3, 5, 30));
	figures.push_back(new Circle(5));
	figures.push_back(new Rectangle(4, 6));
	figures.push_back(new Square(7));
	figures.push_back(new Rhombus(3.5, 60));
	for(int i = 0; i < 5; i++) {
		cout << figures[i]->area() << " ";
		delete figures[i];
	}
	cout << "\n\n";

	// 3.2
	Car car; cout << endl;
	Bus bus; cout << endl;
	PassengerCar pCar; cout << endl;
	Minivan van; cout << "\n\n";	
	
	// 3.3
	Fraction f1(5, 7);
	Fraction f2(3, 4);
	Fraction f3(10, 14);
	(f1 + f2).print();
	(f1 - f2).print();
	(f1 * f2).print();
	(f1 / f2).print();
	(-f1).print();
	cout << (f1 == f2) << " ";
	cout << (f1 == f3) << " ";
	cout << (f1 != f2) << " ";
	cout << (f1 != f3) << " ";
	cout << (f1 > f2) << " ";
	cout << (f1 <= f2) << " ";
	cout << (f1 < f2) << " ";
	cout << (f1 >= f2) << "\n\n";	
	
	// 3.4
	Card cards[] { 
		Card(King, Hearts, true),
		Card(Ten, Diamonds, false),
		Card(Two, Spades, false),
		Card(Nine, Clubs, false),
		Card(Jack, Clubs, false),
		Card(Ace, Diamonds, true)
	};
	for(int i = 0; i < sizeof(cards) / sizeof(Card); i++)
		cout << cards[i].getValue() << " ";
	
	return 0;
}