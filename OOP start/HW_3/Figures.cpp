/*
1.	Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
using namespace std;
#include <cmath>
class Figure {
public:
	Figure() {}	
	virtual double area() const = 0;
protected:	
	const double PI = 3.141592653589793;
};

class Parallelogram : public Figure {
public:
	Parallelogram(double aSide, double bSide, double angle) : 
		aSide(aSide), bSide(bSide), angle(angle * PI / 180) { }
	
	double area() const override {
		if(angle < 0 || angle > 180) {
			cout << "Sorry, this figure does not exist!\n";
			return -1;
		}
		
		return aSide * bSide * sin(angle);
	}
	
protected:
	double aSide;
	double bSide;
	double angle;	
};

class Rectangle : public Parallelogram {
public:
	Rectangle(double aSide, double bSide) : Parallelogram(aSide, bSide, 90) {}
};

class Square : public Parallelogram {
public:
	Square(double side) : Parallelogram(side, side, 90) {}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(double side, double angle) : Parallelogram(side, side, angle) {}
};
class Circle : public Figure {
public:
	Circle(double radius) : radius(radius) {}
	
	double area() const override {
		if(radius < 0) {
			cout << "Sorry, this figure does not exist!\n";
			return -1;
		}
		
		return PI * radius * radius;
	}
private:
	double radius;
};