void insertSort(int* arr, int size) {
	int temp;
	for(int i = 1; i < size; i++) {
		temp = arr[i];
		for(int j = 0; j <= i; j++) {
			if(temp < arr[j]) {
				for(int k = i; k > j; k--)
					arr[k] = arr[k - 1];
				arr[j] = temp;
				break;
			}
		}
	}
}

void hoarSort(int* arr, int first, int last) {
	int i = first;
	int j = last;	
	int refElem = arr[(first + last) / 2];
	int temp;
	 
	do {
		while (arr[i] < refElem) i++;
		while (arr[j] > refElem) j--;
		
		if(i <= j) {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	
	if(i < last) hoarSort(arr, i, last);
	if(j > first) hoarSort(arr, first, j);
}

int getRefId(int* arr, int size) {
	int refId = 0;	
	int avgValue = (arr[0] + arr[size/2] + arr[size])/3;
	int minDeviation = 10000;
	int deviation;
	for(int i = 0; i < size; i++) {
		deviation = abs(avgValue - arr[i]);
		if(deviation < minDeviation) {
			minDeviation = deviation;
			refId = i;
		}
	}
	
	//cout << arr[refId] << " " << deviation << "\n";
	return refId;
}

void quickSort(int* arr, int size) {
	if(size <= 10) {
		//cout << "Insert sort:\n";
		insertSort(arr, size);
		return;
	} 
	
	int refId = getRefId(arr, size);
	int temp = arr[size/2];
	arr[size/2] = arr[refId];
	arr[refId] = temp;
	
	//cout << "\nHoar sort:\n";
	hoarSort(arr, 0, size - 1);
}