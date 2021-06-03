namespace ex_5 {
	void printArr(int* arr, int size) {
		for(int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	// 5.1
	bool switchValues(int* arr, int size) {
		for(int i = 0; i < size; i++) 
			arr[i] = arr[i] ^ 1;
		return true;
	}

	// 5.2
	bool fillArr(int* arr, int size) {
		for(int i = 0; i < size; i++) 
			arr[i] = 1 + i * 3;
		return true;
	}

	// 5.3
	int getBalanceId(int*, int);

	bool checkBalance(int* arr, int size) {
		int balanceId = getBalanceId(arr, size);
		if(balanceId == -1) {
			std::cout << "No place where balance is reached in array:" << std::endl;
			printArr(arr, size);
			return false;
		} else {
			printf("Balance reached on element id = %i in array:\n", balanceId);
			printArr(arr, size);
			return true;
		}
	}

	int getBalanceId(int* arr, int size) {
		int sumLeft, sumRight;
		for(int i = 0; i < size; i++) {
			sumLeft = 0; sumRight = 0;
			for(int j = 0; j <= i; j++) 
				sumLeft += arr[j];
			
			for(int k = i + 1; k < size; k++)
				sumRight += arr[k];
			
			//std::cout << sumLeft << " " << sumRight << std::endl;
			
			if(sumRight == sumLeft) 
				return i;
		}
		
		return -1;
	}

	// 5.4
	void pushElem(int*, int);
	void pullElem(int*, int);

	bool spinArr(int* arr, int size, int n) {
		if(n == 0) return true;
		
		void (*f) (int*, int);
		int counter = 0;
		int sign = n > 0 ? 1 : -1;
		f = n > 0 ? pushElem : pullElem;
		while(counter != n) {
			f(arr, size);
			counter += sign;
		}
		
		return false;
	}

	void pushElem(int* arr, int size) {
		int temp = arr[size-1];
		for(int i = size - 1; i > 0; i--) {
			arr[i] = arr[i-1];
		}
		arr[0] = temp;
	}

	void pullElem(int* arr, int size) {
		int temp = arr[0];
		for(int i = 0; i < size - 1; i++)
			arr[i] = arr[i+1];
		arr[size - 1] = temp;
	}

	// 5.5
	void switchValues(int size, ...) {
		va_list list;
		va_start(list, size);
		for(int i = 0; i < size; i++) 
			std::cout << (va_arg(list, int) ^ 1) << " ";
		std::cout << std::endl;
		va_end(list);
	}
}