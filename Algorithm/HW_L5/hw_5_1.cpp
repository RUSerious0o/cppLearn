#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

typedef enum order {Ascending, Descending} Order;
const int SIZE_1 = 6;
const int SIZE_2 = 6;

void fillTwoDimArr(vector<int>* , int, int, int);
void printTwoDimArr(vector<int>* , int, int, int);
	
void bubbleSortTwoDimArr(vector<int>* , int, int, Order);
void compareAndSwapValues(int&, int&, Order, bool&);
void swapValues(int&, int&);

int main(int argc, char ** argv) {
	system("cls");
	vector<int> arr[SIZE_1];
	fillTwoDimArr(arr, SIZE_1, SIZE_2, 30);
	printTwoDimArr(arr, SIZE_1, SIZE_2, 4);
	cout << endl;
	
	bubbleSortTwoDimArr(arr, SIZE_1, SIZE_2, Ascending);
	printTwoDimArr(arr, SIZE_1, SIZE_2, 4);
	cout << endl;
	
	bubbleSortTwoDimArr(arr, SIZE_1, SIZE_2, Descending);
	printTwoDimArr(arr, SIZE_1, SIZE_2, 4);
	
	return 0;
}

void bubbleSortTwoDimArr(vector<int>* arr, int size_1, int size_2, Order order) {
	bool finished = false;
	while(!finished) {
		finished = true;
		for(int i = 0; i < size_1; i++) {
			for(int j = 0; j < size_2; j++) {
				if(i == size_1 - 1 && j == size_2 - 1) break;
				if(j == size_2 - 1) {
					compareAndSwapValues(arr[i][j], arr[i + 1][0], order, finished);
				} else {
					compareAndSwapValues(arr[i][j], arr[i][j + 1], order, finished);
				}
			}
		}
	}
}

void compareAndSwapValues(int &value_1, int &value_2, Order order, bool &swapSkipped) {
	if(value_1 > value_2 && order == Ascending) {
		swapValues(value_1, value_2);
		swapSkipped = false;
	} else if(value_1 < value_2 && order == Descending) {
		swapValues(value_1, value_2);
		swapSkipped = false;
	}
}

void swapValues(int &value_1, int &value_2) {
	int temp;
	temp = value_2;
	value_2 = value_1;
	value_1 = temp;
}


void fillTwoDimArr(vector<int>* arr, int size_1, int size_2, int valueRange) {
	srand(time(0));	
	for(int i = 0; i < size_1; i++) {
		for(int j = 0; j < size_2; j++) {
			arr[i].push_back(rand() % valueRange);
		}
	}
}

void printTwoDimArr(vector<int>* arr, int size_1, int size_2, int spacing) {
	char format[8]; 
	sprintf(format, "%%%dd", spacing);
	for(int i = 0; i < size_1; i++) {
		for(int j = 0; j < size_2; j++) {
			printf(format, arr[i][j]);
		}
		cout << "\n";
	}
}