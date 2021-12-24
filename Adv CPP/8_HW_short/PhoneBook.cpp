#include "PhoneBook.h"

const string PhoneBook::NOT_FOUND = "not found";
const string PhoneBook::MORE_THAN_ONE = "found more than 1";

PhoneBook::PhoneBook(ifstream& file) {
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

void PhoneBook::sortByName() {
	sort(items.begin(), items.end(), PersonSorter());
}

void PhoneBook::sortByPhone() {
	sort(items.begin(), items.end(), PhoneSorter());
}

tuple<string, PhoneNumber> PhoneBook::getPhoneNumber(const string& surname) {
	int counter = 0;
	tuple<string, PhoneNumber> result;

	get<0>(result) = NOT_FOUND;
	for (pair<Person, PhoneNumber>& item : items) {
		if (item.first.surName == surname) {
			if (++counter > 1) {
				get<0>(result) = MORE_THAN_ONE;
				return result;
			}

			get<1>(result) = item.second;
		}
	}
	if (counter == 1) get<0>(result) = "";
	return result;
}

void PhoneBook::changePhoneNumber(const Person & person, const PhoneNumber & newnumber) {
	for (pair<Person, PhoneNumber>& item : items) {
		if (item.first == person) {
			item.second = newnumber;
		}
	}
}

ostream& operator << (ostream& out, const PhoneBook& book) {
	for (pair<Person, PhoneNumber> item : book.items) {
		out << item.first << " " << item.second << endl;
	}
	return out;
}