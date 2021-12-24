#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <optional>
#include <fstream>
#include <tuple>
#include <algorithm>

#include "Person.h"
#include "PhoneNumber.h"

using namespace std;

class PhoneBook {
public:
	PhoneBook(ifstream& file);

	void sortByName();

	void sortByPhone();

	tuple<string, PhoneNumber> getPhoneNumber(const string& surname);

	void changePhoneNumber(const Person& person, const PhoneNumber& newnumber);

	friend ostream& operator << (ostream&, const PhoneBook&);
private:
	static const string NOT_FOUND;
	static const string MORE_THAN_ONE;

	vector<pair<Person, PhoneNumber>> items;

	struct PersonSorter {
		bool operator() (const pair<Person, PhoneNumber>& left, const pair<Person, PhoneNumber>& right) {
			return left.first < right.first;
		}
	};

	struct PhoneSorter {
		bool operator() (const pair<Person, PhoneNumber>& left, const pair<Person, PhoneNumber>& right) {
			return left.second < right.second;
		}
	};
};

