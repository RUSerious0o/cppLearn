#include <iostream>
#include <cstdarg>
#include "data.h"
#include "ex_5_func.h"

int main() {
	using namespace ex_5;
	bool (*f) (int*,int);
	
	// 5.1
	f = switchValues;
	int size = sizeof(intArr) / sizeof(int);
	printArr(intArr, size);	
	f(intArr, size);
	printArr(intArr, size);
	
	// 5.2
	f = fillArr;
	f(arr2, ARR_SIZE_2);
	printArr(arr2, ARR_SIZE_2);
	
	// 5.3
	std::cout << std::endl;
	size = sizeof(arr3) / sizeof(int);
	f = checkBalance;
	f(arr3, size);
	
	size = sizeof(arr3_1) / sizeof(int);
	f(arr3_1, size);
	
	size = sizeof(arr3_2) / sizeof(int);
	f(arr3_2, size);
	
	// 5.4	
	size = sizeof(arr4) / sizeof(int);
	std::cout << std::endl << "Base array :" << std::endl;
	printArr(arr4, size);
	
	for(int i = 0; i < sizeof(nArr) / sizeof(int); i++) {
		printf("Spin by %i:\n", nArr[i]);
		spinArr(arr4, size, nArr[i]);
		printArr(arr4, size);
	}
	
	// 5.5
	std::cout << std::endl;
	switchValues(6, 1,1,0,1,0,1);
	
	return 0;
}