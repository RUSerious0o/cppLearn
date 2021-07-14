void fillArr(int **, int, int);

int ** getArr(int rows, int cols) {
	int ** result = new int*[rows];
	if(!result) {
		std::cout << "Malloc failed\n";
		return nullptr;
	}
	
	for(int i = 0; i < rows; i++){
		result[i] = new int[cols];
		if(!result[i]) {
			std::cout << "Malloc failed\n";
			return nullptr;
		}
	}
	
	fillArr(result, rows, cols);
	
	return result;
}

void fillArr(int ** arr, int rows, int cols) {
	for(int i = 0; i < rows; i++) 
		for(int j = 0; j < cols; j++)
			arr[i][j] = (i+1) * (j+1);
}

void printArr(int ** arr, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++)
			printf("%3d", arr[i][j]);
		std::cout << "\n";
	}
}

void deleteArr(int ** arr, int rows) {
	for(int i = 0; i < rows; i++) 
		delete [] arr[i];
	delete [] arr;
}