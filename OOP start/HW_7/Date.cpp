//1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.Перегрузите оператор вывода для данного класса.Создайте два "умных" указателя today и date.Первому присвойте значение сегодняшней даты.Для него вызовите по отдельности методы доступа к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.Затем переместите ресурс, которым владеет указатель today в указатель date.Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

#pragma once

#include <ostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
public:
	Date(int day, int month, int year) : day(day % 31), month(month % 12), year(year) {}

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}

	string toString() {
		stringstream ss;
		ss << day << '.' << month << '.' << year;
		return ss.str();
	}

	friend ostream& operator<<(ostream& out, const Date& date);
private:
	int day, month, year;

};

ostream& operator<<(ostream& out, const Date& date) {
	out << setfill('0') << setw(2) << date.day << '.'
		<< setw(2) << date.month << '.'
		<< date.year;

	return out;
}