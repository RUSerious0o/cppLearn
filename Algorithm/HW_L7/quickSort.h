void insertSort(int*, int, int);
void hoarSort(int*, int&, int&);
void quickSort(int*, int, int);
void setMedian(int&, int&, int&);

void quickSort(int* arr, int first, int last) {
	if(last - first <= 10) {
		insertSort(arr, first, last);
	} else {
		setMedian(arr[first], arr[first + (last - first) / 2], arr[last]);
		
		int leftPointer = first;
		int rightPointer = last;
		hoarSort(arr, leftPointer, rightPointer);
		
		if(leftPointer < last) quickSort(arr, leftPointer, last);
		if(rightPointer > first) quickSort(arr, first, rightPointer);
	}
}

void setMedian(int &first, int &middle, int &last) {
	// if 2 of 3 elements are equal - do nothing
	if(first == middle || first == last || middle == last) return;	
	// if middle element IS median - do nothing
	if((middle > first && middle < last) || (middle < first && middle > last)) return;
		
	if((first > middle && first < last) || (first < middle && first > last)) {
		std::swap(first, middle);
		return;
	}
	
	if((last > first && last < middle) || (last < first && last > middle)) {
		std::swap(last, middle);
		return;
	}
}

void insertSort(int* arr, int first, int last) {
	if(last - first < 1) return;
	
	int temp;
	for(int i = first + 1; i <= last; i++) {
		temp = arr[i];
		for(int j = 0; j < i; j++) {
			if(temp < arr[j]) {
				for(int k = i; k > j; k--) {
					arr[k] = arr[k - 1];
				}
				arr[j] = temp;
				break;
			}
		}
	}
}

void hoarSort(int* arr, int &leftPointer, int &rightPointer) {
	int refElem = arr[leftPointer + (rightPointer - leftPointer) / 2];
	 
	do {
		while (arr[leftPointer] < refElem) leftPointer++;
		while (arr[rightPointer] > refElem) rightPointer--;
		
		if(leftPointer <= rightPointer) {
			std::swap(arr[leftPointer], arr[rightPointer]);
			leftPointer++;
			rightPointer--;
		}
	} while (leftPointer <= rightPointer);
}

