/*
1.	Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
2.	Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
3.	Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
*/

template <typename T>
class Pair1 {
public:
	Pair1(T first, T second) : firstValue(first), secondValue(second) { }
	
	T first() const { return firstValue; }
	T second() const { return secondValue; }
private:
	T firstValue;
	T secondValue;
};

template <typename T, typename U>
class Pair {
public:
	Pair(T first, U second) : firstValue(first), secondValue(second) { }
	
	T first() const { return firstValue; }
	U second() const { return secondValue; }
private:
	T firstValue;
	U secondValue;
};

template <typename T>
class StringValuePair : public Pair<std::string, T> {
public:
	StringValuePair(std::string str, T value) : Pair<std::string, T>(str, value) {}
};
