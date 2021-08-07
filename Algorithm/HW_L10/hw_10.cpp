#include <iostream>
#include "MyStack.h"

using namespace std;

bool checkBracketSequence(std::string);

int main(int argc, char ** argv) {
	system("cls");
	// 10.1
	string str[] = {"()", "([])()", "{}()", "([{}])", ")(", "())({)", 
					"(", "])})", "([(])", "(2+(2*2))", "[2/{5*(4+7)}]", "" };
	for(int i = 0; i < 12; i++)
		cout 	<< "Braces sequence " << str[i] << " is " 
				<< (checkBracketSequence(str[i]) ? "correct" : "wrong") << "\n";
	
		
	// 10.2
	cout << "\n";
	MyStack baseStack;
	char arr[] = {'H','e','l','l','o',' ','w','o','r','l','d','!'};
	for(int i = 0; i < sizeof(arr)/sizeof(char); i++) {
		baseStack.push(arr[i]);
	}
	
	MyStack newStack = baseStack.copy();
	
	baseStack.pop();
	baseStack.pop();
	baseStack.print();
	
	newStack.push('!');
	newStack.print();

	// 10.3
	MyStack incStack;
	MyStack decStack;
	MyStack mStack;
	char arr_inc[] = {71,70,69,68,67,66,65,64};
	char arr_dec[] = {72,73,74,75,76,77,78,79};
	char arr__ms[] = {76,78,80,64,70,80,77,73};
	for(int i = 0; i < 7; i++) {
		incStack.push(arr_inc[i]);
		decStack.push(arr_dec[i]);
		mStack.push(arr__ms[i]);
	}
	
	cout << "\nStack :"; 
	incStack.print(); 
	cout << (incStack.isIncreasing() ? "Is sorted (increasing)\n" : "Is not increasing\n");
	cout << (incStack.isDecreasing() ? "Is sorted (decreasing)\n" : "Is not decreasing\n");
	
	cout << "\nStack :"; 
	decStack.print(); 
	cout << (decStack.isIncreasing() ? "Is sorted (increasing)\n" : "Is not increasing\n");
	cout << (decStack.isDecreasing() ? "Is sorted (decreasing)\n" : "Is not decreasing\n");
	
	cout << "\nStack :"; 
	mStack.print(); 
	cout << (mStack.isIncreasing() ? "Is sorted (increasing)\n" : "Is not increasing\n");
	cout << (mStack.isDecreasing() ? "Is sorted (decreasing)\n" : "Is not decreasing\n");

	return 0;
}

bool checkBracketSequence(std::string s) {					// 10.1
	if(s.size() == 0) {
		return false;
	}
	
	int i = 0;	
	MyStack stack;
	while(s[i] != '\0') {
		if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
			stack.push(s[i]);
		}
		
		if(s[i] == '}' || s[i] == ')' || s[i] == ']') {
			char temp = stack.pop();
			if(s[i] == '}' && temp != '{') return false;
			if(s[i] == ']' && temp != '[') return false;
			if(s[i] == ')' && temp != '(') return false;
		}
		
		i++;
	}
	
	if(stack.getSize() != 0) return false;
	else return true;
}