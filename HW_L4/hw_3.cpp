#include <iostream>

using namespace std;

void printIntBin(int);
int exp(int, int);
int expRec(int, int);
int expRecEven(int, int);

#include "chess_king.h"

int main(int argc, char ** argv) {
	system("cls");

	//4.1
	printf("%i\n", 0b110101011001);				// 3417
	printIntBin(3417); cout << "\n";
	printIntBin(1708); cout << "\n\n";
	
	//4.2 - 4.4
	printf("%i %i %i %i %i\n\n", exp(3,7), expRec(3,7), expRecEven(3,7), expRecEven(3,8), expRecEven(3,10));		// 2187, 6561, 59049
	
	//4.5
	initField();	
	
	setObstacle(2, 2);
	setObstacle(1, 2);
	setObstacle(5, 3);
	setObstacle(0, 4);
	setObstacle(1, 4);
	setObstacle(3, 0);
	setObstacle(5, 0);
	
	printField();
	
	return 0;
}

//4.1
void printIntBin(int num) {
	if(num <= 1) {
		cout << num;
		return;	
	}
	
	printIntBin(num >> 1);
	cout << num % 2;	
}

//4.2
int exp(int base, int grade) {
	if(grade <= 1) return base;
	int result = 1;
	for(int i = 0; i < grade; i++)
		result *= base;
	return result;
}

//4.3
int expRec(int base, int grade) {
	if(grade <= 1) return base;	
	return base * expRec(base, grade - 1);
}

//4.4
int expRecEven(int base, int grade) {
	if(grade <= 1) return base;
	if(grade % 2 == 0) return expRecEven(base * base, grade / 2);		
	else return base * expRecEven(base, grade - 1);
}

