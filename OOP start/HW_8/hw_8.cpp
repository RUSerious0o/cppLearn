//1.	Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
//2.	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра.Написать класс Bar, хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.Если y + a > 100, возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
//3.	Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.Эти методы должны запускать классы - исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда(направление не находится в нужном диапазоне).Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.


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