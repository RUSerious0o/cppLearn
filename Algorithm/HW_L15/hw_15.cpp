#include <iostream>

using namespace std;

/*
1.	Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
2.	Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.
*/

int hashString(string s) {
	int sum = 0;
	int i = 0;
	while(s[i] != '\0') {		
		sum += (int) s[i++];		
	}
	return sum;
}

void greedSum(int target) {
	if(target < 0 ) return;
	
	cout << "Target sum is: " << target << ", coins taken: ";
	int values[] = {50, 10, 5, 2, 1};	
	int coinsCount = 0;
	int sum = 0;
	
	int dif;
	while(sum < target) {
		dif = target - sum;
		for(int i = 0; i < sizeof(values) / sizeof(int); i++) {
			if(values[i] > dif) continue;
			sum += values[i];
			cout << values[i];			
			coinsCount++;
			break;			
		}
		if(sum < target) cout << " ";
	}	
	cout << ", coins count: " << coinsCount << "\n";
}

int main() {
	// 15.1
	cout << "String \"Hello!\" hash is " << hashString("Hello!") << endl;
	
	// 15.2
	greedSum(98);
	greedSum(33);
	greedSum(257);
	
	return 0;
}