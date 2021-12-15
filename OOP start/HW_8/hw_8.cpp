//1.	�������� ��������� ������� div, ������� ������ ��������� ��������� ������� ���� ���������� � ��������� ���������� DivisionByZero, ���� ������ �������� ����� 0. � ������� main �������� ��������� ������ ������� div � �������, � ����� ������ ����������.
//2.	�������� ����� Ex, �������� ������������ ����� x � ������� ����������� �� ������������� �����, ���������������� x ��������� ���������.�������� ����� Bar, �������� ������������ ����� y(����������� �� ��������� �������������� ��� �����) � ������� ����� set � ������������ ������������ ���������� a.���� y + a > 100, ������������ ���������� ���� Ex � ������� a* y, ����� � y ��������� �������� a.� ������� main ������� ���������� ������ Bar � � ����� � ����� try ������� � ���������� ����� n.������������ ��� � �������� ��������� ������ set �� ��� ���, ���� �� ����� ������� 0. � ����������� ���������� �������� ��������� �� ������, ���������� ������ ������� ����������.
//3.	�������� ����� ������, ������������ ����������� ������ �� ����� 10x10, � �������� ���� �����, ���������� ������� ������������� �� �������� �������.��� ������ ������ ��������� ������ - ���������� OffTheField, ���� ����� ������ ���� � �����, � IllegalCommand, ���� ������ �������� �������(����������� �� ��������� � ������ ���������).������ ���������� ������ ��������� ��� ����������� ���������� � ������� ������� � ����������� ��������.�������� ������� main, ������������ ���� ������� � ��������������� ��� ���������� �� ��� �������, � ����� ��������� ��������� ���������� � ���� ����������� �������.


#include <iostream>
#include <string>

#include "Robot.cpp"

using namespace std;

template <typename T>
double div(T dividend, T divider) {
	if (divider == 0)
		throw "Division by zero!";

	return (double)dividend / divider;
}

class Ex {
public:
	Ex(double x) : x(x) {}	

	double get() { return x; }
private:
	double x;
};

class Bar {
public:
	Bar() : y(0) {}

	void set(double a) {
		if (y + a > 100) throw Ex(a * y);
		y = a;
	}
private:
	double y;
};

int main() {
	system("cls");
	
	// 8.1
	try {		
		cout << div<int>(3, 4) << " " << div<double>(0.25, 0);
	}
	catch (const char* err) {
		cerr << err << endl;
	}

	// 8.2
	try {		
		Bar bar;
		int number;
		do {			
			cin >> number;
			bar.set(number);
		} while (number != 0);
	}
	catch (Ex err) {
		cerr << "Bad input: your a*y = " << err.get() << endl;
	}
	system("pause");

	// 8.3
	try {
		Robot robot;
		robot.place(4, 4);
		do {
			system("cls");
			robot.print();
			robot.move();
		} while (true);
	}
	catch (const RobotError& err) {
		cerr << err << endl;
	}

	return 0;
}