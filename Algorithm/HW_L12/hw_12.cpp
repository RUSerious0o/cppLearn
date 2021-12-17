#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../../mylib.h"
#include "BinTree.h"

using namespace std;

/* Task:
1. Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
2. создаст [50] деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями;
3. рассчитает, какой процент из созданных деревьев является сбалансированными.
4. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
*/

int main() {
	system("cls");
	srand(time(0));
	
	// 12.1 - 12.3
	int treesCount = 50;
	int valuesRange = 100000;
	int valuesCount = 10000;
	int balancedTrees = 0;
	int manuallyBalancedTreesCount = 0;
	
	BinTree tree[treesCount];
	for(int i = 0; i < treesCount; i++) {
		tree[i] = BinTree(valuesCount, valuesRange);		
		
		if(i % 5 == 0) {
			tree[i].balance();
			manuallyBalancedTreesCount++;
		}
		
		if(tree[i].checkBalance()) balancedTrees++;
	}
	printf("Balanced trees: %d of %d (%.0f%%), including\n%d manually balanced trees and %d naturally balanced trees\n", 
		balancedTrees, treesCount, ((float) balancedTrees * 100 / treesCount), 
		manuallyBalancedTreesCount, balancedTrees - manuallyBalancedTreesCount);

	
	// 12.4
	BinTree tr;
	tr.insert(0);
	tr.insert(1);
	tr.insert(7);
	tr.insert(13);
	tr.insert(19);
	tr.insert(6);
	tr.insert(5);
	tr.insert(27);
	
	cout << "\n";
	tr.balance();
	tr.print(); 
	
	int arr[] = {7,10,13,19,30,0,1,7};
	for(int i = 0; i < 8; i++) {
		cout << arr[i] << " is " << (tr.find(arr[i]) ? "found" : "missing") << "\n";
	}
	
		
	return 0;
}