#include <iostream>
#include <cmath>

using namespace std;

#include "data.h"
#define SIZE(arr) sizeof((arr))/sizeof(int)
#include "quickSort.h"

void printArr(int* arr, int size) {
	int sum = 0;
	printf("\n");
	for(int i = 0; i < size; i++) {
		sum += arr[i];
		printf("%4d%c", arr[i], i > 1 && (i + 1) % 14 == 0 ? '\n' : ' ');
		
	}
	//printf("\nChecksum :%d\n", sum);
}

void sortedInsert(int* bucket, int size, int elem) {
	//в качестве счетчика элементов в корзине используем первый элемент массива
	int counter = ++bucket[0];
	int i;
	for(i = 1; i < counter; i++) {
		if(elem > bucket[i]) {
			for(int j = counter + 1; j > i; j--) {
				bucket[j] = bucket[j - 1];
			}
			bucket[i] = elem;
			return;
		}		
	}
	bucket[i] = elem;
}

// по корзинам делим по степеням 8-ки
int getBucketNum(int value, int bucketCount) {
	int num = 0;
	// в корзину кладем в инвертированном порядке, чтобы удобнее было доставать
	for(int i = 0; i < bucketCount; i++) {
		value = value >> 3;
		if(value == 0) return i;
	}
	
	return bucketCount;
}

int main(int argc, char ** argv) {
	int* arr;
	int size;
			
	{ // 7.1 
		system("cls");
		cout << "===== 7.1 ===== Quick sort\n";
		arr = arr_1; size = SIZE(arr_1);
		
		printArr(arr, size);
		quickSort(arr, size);
		cout << "\n";
		printArr(arr, size);
	}
	
	// 7.2
	cout << "\n\n===== 7.2 ===== Bucket sort, even positive numbers\n";
	arr = arr_4; size = SIZE(arr_4);	
	const int BUCKETS_COUNT = 10;
	int bucket[BUCKETS_COUNT][size + 1];
	for(int i = 0; i < BUCKETS_COUNT; i++) bucket[i][0] = 0;
	
	printArr(arr, size);
	
	for(int i = 0; i < size; i++) {
		if(arr[i] != 0 && arr[i] % 2 == 0) { 
			sortedInsert(bucket[getBucketNum(arr[i], BUCKETS_COUNT)], size + 1, arr[i]);
			arr[i] = -1;
		}
	}
	
	for(int i = 0; i < size; i++) {
		if(arr[i] == -1) {
			for(int j = 0; j < BUCKETS_COUNT; j++) {
				if(bucket[j][0] > 0) {
					arr[i] = bucket[j][bucket[j][0]];
					bucket[j][0]--;
					
					break;
				}
			}
		}
	}

	cout << "\n";
	printArr(arr, size);
	cout << "\n";
	
	return 0;
}