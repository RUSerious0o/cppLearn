#include <iostream>
#include "func.h"

#define IS_IN_RANGE(a, b) ( (a)*(b) < 0 ? false : (a)*(a) < (b)*(b) ? true : false )
#define GET_ELEM(arr, row, col) *(*(arr+row)+col)
#define ARR_LENGTH(arr, type) sizeof(arr)/sizeof(type)

int main(int argc, char ** argv) {
	// 7.1
	std::cout << IS_IN_RANGE(3, 10) << " " << IS_IN_RANGE(0, 5) << " "
			  << IS_IN_RANGE(-1, 3) << " " << IS_IN_RANGE(-3, -5) << " "
			  << IS_IN_RANGE(15, 10) << " " << IS_IN_RANGE(0.7f, 0.95f) << "\n";	
	
	// 7.2	
	int rows = 5, cols = 4;
	int ** arr = getArr(rows, cols);	
	printArr(arr, rows, cols);	
	std::cout << GET_ELEM(arr, 2, 3) << " " << GET_ELEM(arr, 4, 3);	
	deleteArr(arr, rows);
	
	// 7.3
	int arr2[] = {1,2,3,4,5,6,7,8,9};
	char cArr[] = {'g','e','e','z'};
	std::cout << "\n" << ARR_LENGTH(arr2, int) << " " << ARR_LENGTH(cArr, char) << "\n";
	
	return 0;
}