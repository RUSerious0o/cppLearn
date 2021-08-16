#include <iostream>
#include "binConverter.h"

const int Q_SIZE = 7;

class ExcludePriorityQueue {
public:
	ExcludePriorityQueue(int qSize) {
		queueSize = qSize;
		elemCount = 0;
		value = new int[qSize];
		priority = new int[qSize];
		maxPriority = 0;
	}
	
	void printQueue() {
		for(int i = 0; i < elemCount; i++) {
			printf("[%d,%d] ", value[i], priority[i]);
		}
		printf("\n");
	}
	
	bool insert(int val, int prior) {
		if(elemCount == queueSize) {
			std::cout << "Queue is full\n";
			return false;
		} else {
			value[elemCount] = val;
			priority[elemCount] = prior;
			maxPriority = maxPriority > prior ? maxPriority : prior;
			elemCount++;
			
			return true;
		}
	}
	
	void remove(int &val, int &prior) {
		if(elemCount == 0) {
			printf("Queue is empty!\n");
			return;
		}
		
		for(int i = 0; i < elemCount; i++) {
			if(priority[i] == maxPriority) {
				val = value[i];
				prior = priority[i];
				
				for(int j = i; j < elemCount - 1; j++) {
					value[j] = value[j + 1];
					priority[j] = priority[j + 1];
				}
				
				elemCount--;
				updateMaxPriority();
				
				return;
			}
		}
	}
private:
	int* value;
	int* priority;
	int maxPriority;
	int queueSize;
	int elemCount;
	
	void updateMaxPriority() {
		if(elemCount == 0) {
			maxPriority = 0;
			return;
		}
		
		maxPriority = priority[0];
		for(int i = 0; i < elemCount; i++)
			maxPriority = maxPriority > priority[i] ? maxPriority : priority[i];
	}
};

int main(int argc, char ** argv) {
	system("cls");
	// 9.1
	int v, p;
	ExcludePriorityQueue queue(Q_SIZE);
	queue.insert(12,1);
	queue.insert(24,0);
	queue.insert(17,4);
	queue.insert(3,0);
	queue.insert(9,4);
	queue.printQueue();
	
	for(int i = 0; i < 3; i++) {
		queue.remove(v, p);
		queue.printQueue();
	}
	
	queue.insert(48,4);
	queue.insert(24,6);
	queue.insert(13,1);
	queue.insert(27,2);
	queue.insert(8,7);
	queue.insert(15,3);
	
	queue.printQueue();
	queue.remove(v, p);
	std::cout << "Removed [" << v << "," << p << "]\n";
	queue.printQueue();
	
	for(int i = 0; i < 7; i++) {
		queue.remove(v, p);
		queue.printQueue();
	}
	
	// 9.2
	BinConverter BC[] {0b1101010111, 0b111, 0b1, 0b0, 0b100000111100, 586113};
	for(int i = 0; i < sizeof(BC) / sizeof(BinConverter); i++) {
		std::cout << "Binary representation of your number: " << 
			BC[i].getNumber() << " is: " << BC[i].getBinNumber() << "\n";
	}
	
	return 0;
}