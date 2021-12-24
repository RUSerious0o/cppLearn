#pragma once

#include <iostream>
#include <optional>
#include <string>

using namespace std;

struct Person {
public:
	string name;
	string surName;
	optional<string> patronymic;

	Person(const string& surname, const string& name);

	Person(const string& surname, const string& name, const string& patronymic);

	friend bool operator < (const Person&, const Person&);
	friend bool operator > (const Person&, const Person&);
	friend bool operator == (const Person&, const Person&);
	friend ostream& operator << (ostream&, const Person&);
private:
	static const int NAME_WIDTH = 12;
	static const int SURNAME_WIDTH = 14;
	static const int PATRONYMIC_WIDTH = 16;
};

