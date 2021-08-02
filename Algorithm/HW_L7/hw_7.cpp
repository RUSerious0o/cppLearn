#include <iostream>
#include <cmath>
#include "../../../../mylib.h"

using namespace std;

#include "data.h"
#define SIZE(arr) sizeof((arr))/sizeof(int)
#include "quickSort.h"

void sortedInsert(int*, int, int);
int getBucketNum(int, int);

void bucketSort(int* arr, int size) {
	const int BUCKETS_COUNT = 10;
	int bucket[BUCKETS_COUNT][size + 1];
	for(int i = 0; i < BUCKETS_COUNT; i++) bucket[i][0] = 0;
	
	for(int i = 0; i < size; i++) {
		if(arr[i] % 2 == 0) { 
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
		size = 60;
		arr = getArr(size, 1000);
		
		printArr(arr, size, 5);
		quickSort(arr, 0, size - 1);
		cout << "\n";
		printArr(arr, size, 5);
	}
	
	// 7.2
	cout << "\n\n===== 7.2 ===== Bucket sort, even positive numbers\n";
	size = 40;
	arr = getArr(size, 150);
	printArr(arr, size, 5);
	cout << "\n";
	
	bucketSort(arr, size);
	printArr(arr, size, 5);
	cout << "\n";
	
	return 0;
}