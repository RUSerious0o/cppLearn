//1. �������� ����� Date � ������ ����, �����, ��� � �������� ������� � ���� �����.����������� �������� ������ ��� ������� ������.�������� ��� "�����" ��������� today � date.������� ��������� �������� ����������� ����.��� ���� �������� �� ����������� ������ ������� � ����� ������ Date, � ����� �������� �� ����� ������ ����� ������� � ������� �������������� ��������� ������.����� ����������� ������, ������� ������� ��������� today � ��������� date.���������, �������� �� �������� ��������� today � date � �������� ��������������� ���������� �� ���� � �������.

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