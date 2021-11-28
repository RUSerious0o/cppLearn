#include <iostream>
#include <tuple>
#include <fstream>

#include "Person.cpp"
#include "PhoneNumber.cpp"
#include "PhoneBook.cpp"

using namespace std;

int main(int argc, char** argv) {
	system("cls");
	
	ifstream file{ "PhoneBook.txt" };
	PhoneBook book(file);
	cout << book;

	cout << "\n------Sorted by Phone-------\n" << endl;
	book.sortByPhone();
	cout << book;

	cout << "\n------Sorted by Name--------\n" << endl;
	book.sortByName();
	cout << book;

	cout << "\n-----GetPhoneNumber-----\n" << endl;
	// лямбда функция, которая принимает фамилию и выводит номер телефона этого	человека, либо строку с ошибкой
	auto print_phone_number = [&book](const string& surname) {
		cout << surname << "\t";
		auto answer = book.getPhoneNumber(surname);
		if (get<0>(answer).empty())
			cout << get<1>(answer);
		else
			cout << get<0>(answer);
		cout << endl;
	};

	// вызовы лямбды
	print_phone_number("Ivanov");
	print_phone_number("Petrov");
	print_phone_number("Solovev");

	cout << "\n----ChangePhoneNumber----\n" << endl;
	book.changePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
	book.changePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
	cout << book;

	
	return 0;
}