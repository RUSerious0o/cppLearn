#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <optional>
#include <fstream>
#include <sstream>

using namespace std;

struct Person {
public:
	string name;
	string surName;
	string patronymic;

	Person(const string& name, const string& surname) : name(name), surName(surname), patronymic("-") {}

	Person(const string& name, const string& surname, const string& patronymic) : 
		name(name), surName(surname), patronymic(patronymic) {}

	friend bool operator < (const Person&, const Person&);
	friend bool operator > (const Person&, const Person&);
	friend bool operator == (const Person&, const Person&);
	friend ostream& operator << (ostream&, const Person&);
};

bool operator < (const Person& person_1, const Person& person_2) {
	return	tie(person_1.surName, person_1.name, person_1.patronymic) <
			tie(person_2.surName, person_2.name, person_2.patronymic);
}

bool operator > (const Person& person_1, const Person& person_2) {
	return	tie(person_1.surName, person_1.name, person_1.patronymic) >
			tie(person_2.surName, person_2.name, person_2.patronymic);
}

bool operator == (const Person& person_1, const Person& person_2) {
	return	tie(person_1.surName, person_1.name, person_1.patronymic) ==
			tie(person_2.surName, person_2.name, person_2.patronymic);
}

ostream& operator << (ostream& out, const Person& person) {
	out << person.surName << " " << person.name;
	if(person.patronymic != "-") out << " " << person.patronymic;
	return out;
}

/*class Less {
public:
	bool operator() (const Person& first, const Person& second) {
		return first < second;
	}
};*/



void printPersons(const vector<Person>& persons) {
	for (Person p : persons)
		cout << p << endl;
}

struct PhoneNumber {
	int countryCode;
	int cityCode;
	string number;
	int additionalNumber = -1;

	friend ostream& operator << (ostream&, const PhoneNumber&);
	friend bool operator < (const PhoneNumber&, const PhoneNumber&);
	friend bool operator > (const PhoneNumber&, const PhoneNumber&);
	friend bool operator == (const PhoneNumber&, const PhoneNumber&);
};

ostream& operator << (ostream& out, const PhoneNumber& number) {
	out << "+" << number.countryCode << "(" << number.cityCode << ")" << number.number;
	if (number.additionalNumber > 0) {
		out << " " << number.additionalNumber;
	}
	return out;
}

bool operator < (const PhoneNumber& number_1, const PhoneNumber number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) < 
			tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}

bool operator > (const PhoneNumber& number_1, const PhoneNumber number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) >
			tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}

bool operator == (const PhoneNumber& number_1, const PhoneNumber number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) ==
			tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}

class PhoneBook {
public:
	PhoneBook(ifstream& file) {
		if (!file.is_open()) return;

		for (string line; getline(file, line); ) {
			stringstream buf{ line };
			vector<string> data;
			for (string word; buf >> word; ) {
				data.push_back(word);
			}

			if (data[6] == "-") data[6] = "-1";
			items.push_back(pair<Person, PhoneNumber>{
				Person{ data[0], data[1], data[2] },
				PhoneNumber{ stoi(data[3]), stoi(data[4]), data[5], stoi(data[6]) }				
			});
		}
	}

	friend ostream& operator << (ostream&, const PhoneBook&);
private:
	vector<pair<Person, PhoneNumber>> items;
};

ostream& operator << (ostream& out, const PhoneBook& book) {
	for (pair<Person, PhoneNumber> item : book.items) {
		out << item.first << " " << item.second << endl;
	}
	return out;
}

int main(int argc, char** argv) {
	system("cls");

	/*vector<Person> persons{
		Person{ "Oleg", "Ivanov", "Petrovich" },
		Person{ "Ivan", "Ivanov", "Pavlovich" },
		Person{ "Ivan", "Ivanov", "" },
		Person{ "Chris", "Paul" },
		Person{ "Ivan", "Ivanov", "Sergeevich" }		
	};

	
	printPersons(persons);
	cout << endl;	
	std::sort(persons.begin(), persons.end());
	printPersons(persons);*/
	
	ifstream file{ "PhoneBook.txt" };
	PhoneBook book{ file };

	cout << book;

	/*string s;
	for (string line; getline(file, line); ) {
		stringstream buf{ line };		
		for (string word; buf >> word; ) {
			cout << word << " ";
		}
		cout << endl;
	}*/
	
	return 0;
}