#include <iostream>
#include <list>

#include "Matrix.cpp"
#include "CustomIterator.cpp"

using namespace std;

// 3.1
template <typename T>
void pushBackAverage(list<T> &numbers) {
	double sum = 0;
	for (T number : numbers) {
		sum += number;
	}
	numbers.push_back(sum / numbers.size());
}


int main(int argc, char** argv) {
	system("cls");

	// 3.1
	list<double> numbers{ 1.25, 2.5, 4, 7.6, 9.2, 8 };
	pushBackAverage(numbers);
	pushBackAverage(numbers);
	for (double number : numbers) cout << number << " ";
	cout << "\n\n";

	// 3.2
	Matrix m{ 5 };
	m.print();

	cout << endl;	
	cout << fixed << setprecision(2) << "Determimant: " << m.getDeterminant() << endl;
	m.print();
	cout << endl;

	// 3.3
	CustomContainer values{ 3, 7, -5, 0, 18, 27, -13 };
	for (auto value : values) {
		cout << value << "-2\t= ";
		cout.width(3);
		cout << (value -= 2) << endl;
	}

	return 0;
}