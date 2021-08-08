#include <iostream>

using namespace std;

bool isPrime(int);

int main(int argc, char ** argv) {
	system("cls");

	//3.1
	int number;
	cout << "Please, enter any positive integer: ";
	cin >> number;
	printf("Your number is%s prime\n\n", isPrime(number) ? "" : " not");
		
	return 0;
}

//3.1
bool isPrime(int number) {
	if(number < 0) return false;
	if(number <= 3) return true;
	for(int i = 2; i < number; i++)
		if(number % i == 0) return false;
	return true;
}
