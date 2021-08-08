class MyStack {
public:
	MyStack() {
		size = 0;
		head = (Node*) malloc(sizeof(Node));
		head->value = NULL_CHAR;
		head->nextNode = NULL;
	}
	
	bool push(char c) {
		if(size == 0) {
			head->value = c;
			size++;
			return true;
		}
		
		Node * node = (Node*) malloc(sizeof(Node));
		if(!node) {
			std::cout << "Stack overflow!\n";
			return false;
		}
		
		node->value = head->value;
		node->nextNode = head->nextNode;
		
		head->value = c;
		head->nextNode = node;
		size++;
		
		return true;
	}
	
	char pop() {
		if(size == 0) {
			return NULL_CHAR;
		}
		
		char c = head->value;
		
		if(size > 1) {
			Node * temp = head->nextNode;
			
			head->value = head->nextNode->value;
			head->nextNode = head->nextNode->nextNode;
			
			free(temp);
		} else {
			head->value = NULL_CHAR;
			head->nextNode = NULL;
		}
		
		size--;
		return c;
	}
	
	int getSize() {
		return size;
	}
	
	void print() {
		if(size == 0) {
			std::cout << "Stack is empty!\n";
			return;
		}
		
		Node * temp = head;
		while(temp->nextNode) {
			std::cout << temp->value;
			temp = temp->nextNode;
		}
		std::cout << temp->value << "\n";
	}
	
	MyStack copy() { 									// 10.2
		MyStack newStack;
		
		if(size != 0) 
			copyNode(newStack, head);
		
		return newStack;
	}
	
	bool isIncreasing() {								// 10.3
		if(size == 0) {
			std::cout << "Stack is empty!\n";
			return false;
		}
		
		Node * temp = head;
		while(temp->nextNode) {
			if(temp->value > temp->nextNode->value) {
				return false;
			}
			temp = temp->nextNode;
		}
		
		return true;
	}
	
	bool isDecreasing() {								// 10.4
		if(size == 0) {
			std::cout << "Stack is empty!\n";
			return false;
		}			
		
		Node * temp = head;
		while(temp->nextNode) {
			if(temp->value < temp->nextNode->value) {
				return false;
			}
			temp = temp->nextNode;
		}
		
		return true;
	}
	
private:
	typedef struct Node {
		char value;
		struct Node* nextNode;
	} Node;
	
	static const char NULL_CHAR = '\0';
	int size;
	Node* head;
	
	void copyNode(MyStack &newStack, Node * node) {		// 10.2
		if(node->nextNode) {
			copyNode(newStack, node->nextNode);
		}
		newStack.push(node->value);
	}
};