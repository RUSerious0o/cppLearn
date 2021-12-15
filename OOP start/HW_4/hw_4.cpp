#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "ArrayInt.h"
#include "BinTree.cpp"
#include "../Hand.cpp"
#include "../Card.cpp"

using namespace std;

int main() {
	system("cls");
	// 4.1
	ArrayInt arr;	
	for(int i : {3,7,13,6,2,4,8,777,-15,48})
		arr.push_back(i);
	arr.print();
	arr.sort();
	arr.print();
	arr.pop_back().pop_back().pop_front().pop_front();
	arr.print();
	
	arr.pop_back().pop_front().pop_front().pop_front().pop_front().pop_front().pop_front();
	arr.print();
	cout << endl;
	
	// 4.2
	srand(time(0));
	const int ELEM_COUNT = 200;
	const int ELEM_RANGE = 75;	
	vector<int> arr_4_2;
	for(int i = 0; i < ELEM_COUNT; i++)
		arr_4_2.push_back(rand() % ELEM_RANGE);
	
	cout << "Vector: \n";
	for(int i = 0; i < ELEM_COUNT; i++)
		cout << arr_4_2[i] << " ";
		
	cout << "\n\nUnique elements:\n";
	BinTree tree;
	for(int i = 0; i < ELEM_COUNT; i++)
		tree.insert(arr_4_2[i]);
	tree.printAsArray(); // число различных чисел в данном векторе равно количеству элементов дерева
	
	// 4.3
	Hand hand;
	hand.add(new Card(King, Spades, true));
	hand.add(new Card(Ace, Hearts, true));	
	hand.add(new Card(Three, Diamonds, true));
	hand.add(new Card(Ten, Clubs, true));
	cout << "\nHand value: " << hand.getValue();
	
	hand.clear();
	hand.add(new Card(Ace, Hearts, true));	
	hand.add(new Card(Ace, Diamonds, true));	
	cout << "\nHand value: " << hand.getValue();
	
	return 0;
}