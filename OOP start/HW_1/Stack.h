class Stack {
public:
	Stack() {}
	
	bool push(int value) {
		if(size == 10) {
			std::cout << "Stack is full!\n";
			return false;
		}
		
		values[size++] = value;	
		return true;
	}
	
	int pop() {
		if(size == 0) {
			std::cout << "Stack is empty!\n";
			return NULL_VALUE;
		}		
		
		return values[--size];
	}
	
	int getSize() {
		return size;
	}
	
	void print() {
		if(size == 0) {
			std::cout << "Stack is empty!\n";
			return;
		}
		
		for(int i = 0; i < size; i++)
			std::cout << values[i] << " ";
		std::cout << "\n";
	}

	void reset() {
		for(int i = 0; i < MAX_SIZE; i++)
			values[i] = 0;
		size = 0;
	}
	
private:
	static const int MAX_SIZE = 10;
	int values[MAX_SIZE] = {0};
	static const int NULL_VALUE = -1;
	int size = 0;
};