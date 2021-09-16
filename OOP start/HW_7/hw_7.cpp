#include <iostream>
#include "Date.cpp"
#include "../BlackJack/Game.cpp"

using namespace std;
#define DELIM "  "

/*
2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
●	Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
●	Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
*/

const unique_ptr<Date>& compare(const unique_ptr<Date>& date_1, const unique_ptr<Date>& date_2) {
	long sum_1 = date_1->getYear() * 365 + date_1->getMonth() * 30 + date_1->getDay();
	long sum_2 = date_2->getYear() * 365 + date_2->getMonth() * 30 + date_2->getDay();
	if (sum_1 > sum_2) return date_1;
	return date_2;
}

void swapDates(unique_ptr<Date>& date_1, unique_ptr<Date>& date_2) {
	unique_ptr<Date> temp = move(date_1);
	date_1 = move(date_2);
	date_2 = move(temp);
}

int main() {
	system("cls");
	{ // 7.1
		unique_ptr<Date> today = make_unique<Date>(12, 9, 2021);
		unique_ptr<Date> date;
		cout << "Day: " << today->getDay() << ", month: " << today->getMonth() << ", year: " << today->getYear() << ", date: " << *today << endl;
		date.swap(today);
		cout << (date == nullptr ? "nullptr" : date->toString()) << DELIM
			<< (today == nullptr ? "nullptr" : today->toString()) << endl;

		// 7.2
		unique_ptr<Date> date_1 = make_unique<Date>(3, 11, 2011);
		unique_ptr<Date> date_2 = make_unique<Date>(7, 9, 2012);

		cout << *compare(date_1, date_2) << DELIM << *date_1 << DELIM << *date_2 << endl;
		swapDates(date_1, date_2);
		cout << *compare(date_1, date_2) << DELIM << *date_1 << DELIM << *date_2 << "\n\n";
	}
	system("pause");

	// BlackJack
	char ans;
	do{
		Game game(vector<string>{"Mike", "Sarah"});
		game.play();
		
		cout << "\nDo you want another play? ";
		cin >> setw(1) >> ans;
	} while (ans == 'Y' || ans == 'y');
	

	return 0;
}