#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <list>
#include <iterator>
#include <numeric>

using namespace std;

// 4.1
const int NUMBERS_SIZE = 50;
const int NUMBERS_RANGE = 200;

template <class T, typename U>
void insert_sorted(T &items, const U &newItem) {
	auto pos = find_if(items.begin(), items.end(), [newItem](int item) {
		return newItem < item;
	});
	items.insert(pos, newItem);
}

// 4.2
const int DATA_SIZE = 100;
const int DATA_VALUES_RANGE = 300;

int main(int argc, char** argv) {
	system("cls");

	// 4.1
	srand(time(0));
	vector<int> numbers(NUMBERS_SIZE);
	generate(numbers.begin(), numbers.end(), []() { 
		return rand() % NUMBERS_RANGE; 
	});
	sort(numbers.begin(), numbers.end());	
	
	insert_sorted<vector<int>, int>(numbers, 100);
	insert_sorted<vector<int>, int>(numbers, 150);

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>{ cout, " " });

	cout << endl;
	list<double> otherNumbers{ 1, 2.5, 3.14, 48.5, 99.9 };
	insert_sorted<list<double>, double>(otherNumbers, 7.5);
	for (auto item : otherNumbers) cout << item << " ";
	cout << "\n\n";

	// 4.2
	vector<double> analogData(DATA_SIZE);
	generate(analogData.begin(), analogData.end(), []() {
		return static_cast<double>(rand() % (DATA_VALUES_RANGE * 100)) / 100;
	});

	vector<int> digitalData(DATA_SIZE);
	transform(analogData.begin(), analogData.end(), digitalData.begin(), [](double value) { 
		return static_cast<int>(value);  
	});

	copy(analogData.begin(), analogData.end(), ostream_iterator<double>{ cout, " " });
	cout << "\n\n";
	copy(digitalData.begin(), digitalData.end(), ostream_iterator<double>{ cout, " " });

	cout << "\n\nDigital signal mismatch: "
		<< accumulate(analogData.begin(), analogData.end(), 0.0, [](double sum, double item) {				
				return sum + pow(item - static_cast<int>(item), 2);					
			});

	return 0;
}