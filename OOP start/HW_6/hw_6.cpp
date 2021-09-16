#include <iostream>
#include <iomanip>
#include <fstream>
#include "Parser.cpp"
#include "../BlackJack/Player.cpp"
#include "../BlackJack/House.cpp"

using namespace std;

const string fName("yandex.html");
/*
1.	Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк:
2.	Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/

// 6.1
bool checkInput(string& s) {
	if(s.size() == 0) return false;	
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] - '0' < 0 || s[i] - '0' > 9)
			return false;
	}
	return true;
}

// 6.2
template <class _Elem, class _Traits>
basic_ostream<_Elem, _Traits>& endll(basic_ostream<_Elem, _Traits>& _Ostr) {
	_Ostr.put(_Ostr.widen('\n'));
	_Ostr.put(_Ostr.widen('\n'));
	_Ostr.flush();
	return _Ostr;
}

int main() {
	system("cls");
	// 6.1
	string input;
	do {
		cout << "Please enter integer : ";
		getline(cin, input);
	} while (!checkInput(input));
	cout << "Your integer is : " << stoi(input) << endll;
	
	// 6.3
	Player player("Mike");
	cout << (player.isHitting() ? "true" : "false") << endl;
	player.win();
	player.lose();
	player.push();
	cout << endl;

	House house("Dealer");
	Card* cards[] = {
		new Card(Two, Hearts, false),
		new Card(Ace, Diamonds),
		new Card(Nine, Spades),		
		new Card(Five, Clubs)
	};

	for (Card* c : cards) 
		cout << *c << " ";
	cout << endll;

	for (Card* c : cards) {
		house.add(c);
		cout << house << (house.isHitting() ? " wants more" : " enough") << endl;
	}
	
	house.flipFirstCard();
	cout << house << endll;

	// Допник
	PseudoParser parser(fName);
	parser.printExchangeRates();
	parser.printWeather();	
		
	return 0;
}