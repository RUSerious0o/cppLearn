#include <iostream>
#include <sstream>
#define T int

class BinConverter {
public:
	BinConverter(T num) {
		number = num;
		pointer = -1;
		
		do {
			push(num % 2);
			num = num >> 1;
		} while(num > 0);
	}

	T getNumber() {
		return number;
	}
	
	std::string getBinNumber() {
		std::stringstream ss;
		for(int i = pointer; i >=0; i--)
			ss << buf[i];
		return ss.str();
	}
	
	void printBinNumber() {
		for(int i = pointer; i >=0; i--)
			std::cout << buf[i];
	}

	void push(int elem) {
		buf[++pointer] = elem;
	}
	
	T pop() {
		return buf[pointer--];
	}
	
private:
	T number;
	const static int BUFFER_SIZE = sizeof(T) * 8;
	int buf[BUFFER_SIZE];
	int pointer;	
};