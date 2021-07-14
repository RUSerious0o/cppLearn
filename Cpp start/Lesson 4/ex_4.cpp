#include <iostream>
#include "data.h"
using namespace std;

int main() {
	// 4.1
	int sum = var_1 + var_2;
	cout << ((sum >= 10 && sum <= 20) ? "true" : "false") << " ";
	sum = var_1 + var_3;
	cout << ((sum >= 10 && sum <= 20) ? "true" : "false") << endl;
	
	// 4.2
	bool flag = true;
	for (int i = 0; i < sizeof(numsToCheck) / sizeof(int); i++) {
		if(numsToCheck[i] <= 0) 
			printf("Number %d is not simple\n", numsToCheck[i]);
		else if(numsToCheck[i] <= 3) 
			printf("Number %d is simple\n", numsToCheck[i]);
		else {
			for(int j = 2; j < numsToCheck[i]; j++) {
				if(numsToCheck[i] % j == 0) {
					flag = false;
					break;
				}
			}
			
			printf("Number %d is%s simple\n", numsToCheck[i], flag ? "" : " not");
			flag = true;
		}
	}
	
	// 4.3
	if(NUM_1 == CONTROL_VALUE || NUM_2 == CONTROL_VALUE || NUM_1 + NUM_2 == CONTROL_VALUE)
		cout << "true" << endl << endl;
	
	// 4.4
	for(int i = 0; i < MATRIX_SIZE; i++) {
		matrix[i][i] = 1;
		matrix[i][MATRIX_SIZE - 1 - i] = 1;
	}

	for(int i = 0; i < MATRIX_SIZE; i++) {
		for(int j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	
	// 4.5
	for(int i = 0; i < sizeof(yearsToCheck) / sizeof(int); i++) {
		if(yearsToCheck[i] % 400 == 0)
			printf("Year %d is intercalary\n", yearsToCheck[i]);
		else if(yearsToCheck[i] % 100 == 0 || yearsToCheck[i] % 4 != 0)
			printf("Year %d is not intercalary\n", yearsToCheck[i]);
		else
			printf("Year %d is intercalary\n", yearsToCheck[i]);
	}
	
	return 0;
}