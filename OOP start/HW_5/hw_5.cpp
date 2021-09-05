#include <iostream>

#include "Pairs.cpp"
#include "../BlackJack/GenericPlayer.cpp"

using namespace std;

int main() {
	system("cls");
	// 5.1
	Pair1<int> p1(5,9);
	cout << "Pair: " << p1.first() << " " << p1.second() << endl;
	
	const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << "\n\n";
	
	// 5.2
	Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << "\n\n";

	// 5.3
	StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << "\n\n";

	// 5.4
	GenericPlayer player("Mike");
	player.add(new Card(Ace, Spades));
	player.add(new Card(King, Diamonds));
	player.add(new Card(Queen, Hearts));
	player.add(new Card(Three, Clubs));
	cout << "Player: " << player.getName() << " has " << player.getTotal() << "\n";
	player.boost();
	
	GenericPlayer ai("Spike");
	ai.add(new Card(Ten, Spades));
	ai.add(new Card(Ace, Diamonds));
	ai.add(new Card(Two, Hearts));
	ai.add(new Card(Four, Clubs));
	cout << "Player: " << ai.getName() << " has " << ai.getTotal() << "\n";
	ai.boost();
	
	return 0;
}