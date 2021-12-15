#pragma once

#include <iostream>
#include <optional>

using namespace std;

struct Person {
public:
	string name;
	string surName;
	optional<string> patronymic;

	Person(const string& surname, const string& name) : name(name), surName(surname), patronymic("-") {}

	Person(const string& surname, const string& name, const string& patronymic) :
		name(name), surName(surname), patronymic(patronymic) {
	}

	friend bool operator < (const Person&, const Person&);
	friend bool operator > (const Person&, const Person&);
	friend bool operator == (const Person&, const Person&);
	friend ostream& operator << (ostream&, const Person&);
private:
	static const int NAME_WIDTH = 12;
	static const int SURNAME_WIDTH = 14;
	static const int PATRONYMIC_WIDTH = 16;	
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
	out.setf(ios::right);
	out.width(person.SURNAME_WIDTH); out << person.surName;
	out.width(person.NAME_WIDTH); out << person.name;

	out.width(person.PATRONYMIC_WIDTH);
	if (!person.patronymic.has_value()) {
		out << "" << "  ";
		return out;
	}

	if (person.patronymic != "-") {
		out << person.patronymic.value() << "  ";
	}
	else {
		out << "" << "  ";
	}

	return out;
}