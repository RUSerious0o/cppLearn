#include <iostream>
#include <fstream>
#include <sstream>

#include "PhoneBook.h"

int main(int argc, char** argv) {
	std::ifstream file("PhoneBook.txt");
	PhoneBook book(file);

	stringstream ss;
	ss << book;
	cout << ss.str();

	return 0;
}