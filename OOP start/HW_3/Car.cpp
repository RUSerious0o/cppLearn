/*
2.	Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти». 
*/
class Car {
public:
	Car() : company("Company"), model("Model") { cout << "Car "; }
	
	void print() const { cout << company << " " << model << endl; }
protected:
	string company;
	string model;	
};

class PassengerCar : virtual public Car {
public:
	PassengerCar() { cout << "PassengerCar "; }
};

class Bus : virtual public Car {
public:
	Bus() { cout << "Bus "; }
};

class Minivan : public PassengerCar, public	Bus {
public:
	Minivan() { cout << "Minivan"; }
};