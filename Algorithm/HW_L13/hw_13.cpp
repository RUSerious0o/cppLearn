/*
1.	Реализовать обход в глубину с использованием стека
2.	Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями. Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
3.	обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
4.	обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
*/

#include <iostream>
#include "../../../../mylib.h"
#include "../../../../ExcludePriorityQueue.h"
#include <stack>
#include <queue>
#include <cstdarg>

using namespace std;

class SimpleIntGraph {
public:
	SimpleIntGraph(int vCount) {		
		matrix = (int**) malloc(vCount * sizeof(int*));
		for(int i = 0; i < vCount; i++) {
			matrix[i] = (int*) calloc(sizeof(int), vCount);
			if(!matrix[i]) {
				cout << "Memory allocation failed!\n";
				return;
			}
		}
		vertexCount = vCount;
	}	
	
	void printMatrix() { 
		cout << "Matrix: \n";
		printTwoDimArr(matrix, vertexCount, vertexCount, 2); 
	}
	
	bool setLink(int from, int to) {
		if(from < 0 || to < 0 || from > vertexCount || to > vertexCount)
			return false;
		
		matrix[from][to] = 1;
		return true;
	}
	
	bool setLink(int linksCount, ...) {
		int from, to;
		va_list list;		
		va_start(list, linksCount);
		for(int i = 0; i < linksCount; i++) {
			if(i % 2 == 0) from = va_arg(list, int);
			else {
				to = va_arg(list, int);
				if(from < 0 || to < 0 || from > vertexCount || to > vertexCount)
					return false;
				
				matrix[from][to] = 1;
			}
		}
		
		va_end(list);
		return true;
	}
	
	// 13.1 - 13.2
	void depthTraverse(int start) {
		if(!startCheck(start)) return;
		
		cout << "Depth traverse start: " << start << ", path: ";
		
		stack<int> path;
		path.push(start);
		int visited[vertexCount] = {0};
		
		int current;
		while(!path.empty()) {
			current = path.top();
			if(visited[current] != 1) {
				visited[current] = 1;
				cout << current << " ";
			}
			
			for(int i = 0; i < vertexCount; i++) {
				if(matrix[current][i] == 1 && visited[i] != 1) {
					path.push(i);
					current = i;
					break;
				} else if(i == vertexCount - 1) {
					path.pop();
				}
			}
		}
		
		cout << "\n";
	}
	
	// 13.2
	void widthTraverse(int start) {
		if(!startCheck(start)) return;
		
		cout << "Width traverse start: " << start << ", path: ";
		
		queue<int> path;
		int visited[vertexCount] = {0};
		int current = start;
		path.push(start);
		visited[start] = 1;
		
		while(!path.empty()) {
			current = path.front();
			
			for(int i = 0; i < vertexCount; i++) {
				if(matrix[current][i] == 1 && visited[i] != 1) {
					path.push(i);
					visited[i] = 1;
				}
			}
			
			cout << path.front() << " ";
			path.pop();
		}
		
		cout << "\n";
	}
	
	// 13.2
	void viewIncomingLinks() {		
		cout << "Incoming links for vertex: \n";
		int counter;
		for(int i = 0; i < vertexCount; i++) {
			counter = 0;
			for(int j = 0; j < vertexCount; j++) {
				if(matrix[j][i] == 1) counter++;
			}

			printf("#%d -> %d%s ", i, counter, i == vertexCount - 1 ? "" : ",");
		}
		cout << "\n";
	}
	
	// 13.3
	void specialRecursiveTraverse(int start) {
		if(!startCheck(start)) return;
		
		int adjacentCounter = 0;
		int visited[vertexCount] = {0};
		
		cout << "Recursive traverse (deep) from vertex #" << start << " :\n";
		recursiveTraverse(visited, start);
		cout << "\nStart has " << countAdjacentVertexes(start) << " adjacent vertexes\n";
	}
	
	// 13.4
	void viewSortedVertexList() {
		ExcludePriorityQueue queue(vertexCount);
		int counter;
		for(int i = 0; i < vertexCount; i++) {
			counter = 0;
			for(int j = 0; j < vertexCount; j++) {
				if(matrix[j][i] == 1) counter++;
			}
			
			queue.insert(i, counter);
		}
		
		cout << "Soted vertexes (by incoming links, descending):\n";
		int vertexNum, links;
		for(int i = 0; i < vertexCount; i++) {
			queue.remove(vertexNum, links);
			printf("#%d -> %d%s ", vertexNum, links, i == vertexCount - 1 ? "" : ",");
		}
		cout << "\n";
	}
	
private:
	int ** matrix;
	int vertexCount;	
	
	bool startCheck(int start) {
		if(start < 0 || start > vertexCount) {
			cout << "Traverse failed!";
			return false;
		} else return true;
	}
	
	void recursiveTraverse(int * visited, int current) {
		visited[current] = 1;
		cout << current << " ";
		for(int i = 0; i < vertexCount; i++) {
			if(matrix[current][i] == 1 && visited[i] != 1) {
				recursiveTraverse(visited, i);
			}
		}
	}
	
	int countAdjacentVertexes(int vertex) {
		int counter = 0;
		for(int i = 0; i < vertexCount; i++) 
			if(matrix[vertex][i]) counter++;
		return counter;
	}
};

int main() {
	std::system("cls");
	const int VERTEX_COUNT = 7;
	SimpleIntGraph g1(VERTEX_COUNT);
	g1.setLink(40,	
		0,1,	0,2,	
		1,0,	1,3,	1,5,
		2,0,	2,4,	2,5,	2,6,
		3,1,	3,4,	3,5,
		4,2,	4,3,	4,6,
		5,1,	5,2,	5,3,
		6,2,	6,4);
	g1.printMatrix();	
	g1.depthTraverse(0);
	g1.depthTraverse(5);
	cout << "\n";
	g1.widthTraverse(0);
	g1.widthTraverse(5);
	cout << "\n";
	g1.viewIncomingLinks();
	cout << "\n";
	g1.specialRecursiveTraverse(2);
	cout << "\n";
	g1.viewSortedVertexList();
		
	cout << "\n";
	SimpleIntGraph g2(VERTEX_COUNT);
	g2.setLink(32,	
		0,1,	0,2,	
		1,0,	1,2,	1,3,
		2,0,	2,1,	2,3,
		3,1,	3,2,	3,4,	3,5,
		4,3,	
		5,3,	5,6,
		6,5);
	g2.printMatrix();
	g2.depthTraverse(1);
	g2.depthTraverse(3);
	cout << "\n";
	g2.widthTraverse(0);
	g2.widthTraverse(5);
	cout << "\n";
	g2.viewIncomingLinks();	
	cout << "\n";
	g2.specialRecursiveTraverse(2);
	cout << "\n";
	g2.viewSortedVertexList();
	
	return 0;
}