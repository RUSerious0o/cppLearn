#include <iostream>
using namespace std;

extern int e_a, e_b, e_c, e_d;

int main() {
	// 3.1
	int a = 3, b = 2, c = 19, d = 5;
	cout << a * (b + ((float) c / d)) << endl;
	
	// 3.2
	int value = 143;
	int result = value <= 21 ? value - 21 : (value - 21) * 2;
	cout << result << endl;
	
	// 3.3
	cout << e_a * (e_b + ((float) e_c / e_d)) << endl;	
	
	// 3.4
	int arr[3][3][3] {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 18};
	arr[1][1][1] = 257;
	int * p = ** arr;
	cout << * (p + 9 + 3 + 1) << " " << * (p + 1) << " " << * (p + 10) << " " << arr[1][0][1];
}