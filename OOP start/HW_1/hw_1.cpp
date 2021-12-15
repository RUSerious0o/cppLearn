#include <iostream>
#include "Power.h"
#include "RGBA.h"
#include "Stack.h"

using namespace std;

int main() {
	system("cls");
	// 1.1
	cout << "===== 1.1 =====\n";
	Power pw;
	cout << pw.calculate() << "\n\n";
	double arr[] = {0.8, 3, 7.43, -3.3, 31.4};
	for(int i = 0; i < 5; i++) {
		pw.set(0.7, arr[i]);
		cout << pw.calculate() << "\n";	
		
		pw.set(2.3, arr[i]);
		cout << pw.calculate() << "\n";	
		
		pw.set(3.7, arr[i]);
		cout << pw.calculate() << "\n\n";	
	}
	
	// 1.2
	cout << "===== 1.2 =====\n";
	RGBA color;
	color.print();
	RGBA color_2(128, 64, 50, 200);	
	color_2.print();
	
	// 1.3	
	cout << "\n===== 1.3 =====\n";
	Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
	
	return 0;
}