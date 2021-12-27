#include "pch.h"

#include "../8_HW/PhoneBook.h"
#include "../8_HW/Person.cpp"
#include "../8_HW/PhoneNumber.cpp"
#include "../8_HW/PhoneBook.cpp"

#include <vector>
#include <sstream>
#include <fstream>

using std::vector;

class PersonTest : public ::testing::Test {
protected:
	void SetUp() override {
		persons.push_back(Person("Smith", "John"));
		persons.push_back(Person("Smith", "Ann", "Harold"));
		persons.push_back(Person("Smith", "John", "Harold"));
		persons.push_back(Person("Harold", "Bob", "John"));
		persons.push_back(Person("Smith", "John", "Harold"));
	}

	vector<Person> persons;
};

TEST_F(PersonTest, personBefore) {
	ASSERT_LT(persons[0], persons[2]);
	ASSERT_LT(persons[3], persons[1]);
	ASSERT_LT(persons[1], persons[2]);
}

TEST_F(PersonTest, personEqual) {
	ASSERT_EQ(persons[2], persons[4]);
}

TEST_F(PersonTest, personAfter) {
	ASSERT_GT(persons[4], persons[3]);
	ASSERT_GT(persons[2], persons[0]);
	ASSERT_GT(persons[2], persons[1]);
}

TEST_F(PersonTest, outputTest) {
	stringstream ss;
	ss << persons[2];
	ASSERT_EQ(ss.str(), 
		"         Smith        John          Harold  ");
}

class PhoneNumberTest : public ::testing::Test {
protected:
	void SetUp() override {
		numbers.push_back(PhoneNumber{ 7,921,"1234567" });
		numbers.push_back(PhoneNumber{ 7,960,"9876541", 404 });
		numbers.push_back(PhoneNumber{ 7,921,"1234567" });
	}

	vector<PhoneNumber> numbers;
};

TEST_F(PhoneNumberTest, compareOperators) {
	ASSERT_EQ(numbers[0], numbers[2]);
	ASSERT_LT(numbers[0], numbers[1]);
	ASSERT_GT(numbers[1], numbers[2]);
}

TEST_F(PhoneNumberTest, outputTest) {
	stringstream ss;
	ss << numbers[0] << " " << numbers[1];
	ASSERT_EQ(ss.str(), 
		"+7(921)1234567 +7(960)9876541 404");
}

class PhoneBookTest : public ::testing::Test {
protected:
	void SetUp() override {
		ifstream file(PATH);
		books.push_back(file);
	}

	vector<PhoneBook> books;
	const string PATH = "../8_HW/PhoneBook.txt";
	const vector<string> lines{
		"   Aleksandrov     Georgii                   +493(7637)6114861",
		"       Zaitsev      Zakhar      Artemovich   +125(44)4164751",
		"       Solovev        Alex       Ivanovich   +4(940)2556793",
		"   Aleksandrov     Georgii                   +493(7637)6114861"

	};
};

TEST_F(PhoneBookTest, getNumber) {
	stringstream ss;
	ss << get<0>(books[0].getPhoneNumber("Aleksandrov"));
	EXPECT_EQ(ss.str(), " ");
	ss << get<1>(books[0].getPhoneNumber("Aleksandrov"));
	ASSERT_EQ(ss.str(), " ");	
}

TEST_F(PhoneBookTest, sortByName) {
	books[0].sortByName();

	stringstream ss;
	ss << books[0];
	ASSERT_EQ(ss.str(), " ");
}

TEST_F(PhoneBookTest, sortByNumber) {
	books[0].sortByName();

	stringstream ss;
	ss << books[0];
	ASSERT_EQ(ss.str(), " ");
}