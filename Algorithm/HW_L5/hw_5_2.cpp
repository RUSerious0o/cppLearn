#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double TPK (double x) {
	return sqrt(fabs(x)) + 5 * pow(x, 3); 
}

int main(int argc, char ** argv) {
	system("cls");
	filebuf fb;
	fb.open("input.txt", ios::in | ios::out);
	iostream buf(&fb);
	
	double arr[11];
	cout << "Your numbers: ";
	for(int i = 0; i < 11; i++) {
		buf >> arr[i];
		cout << arr[i] << (i == 10 ? "" : ", ");
	}
	cout << "\n\n";
	
	int result;
	for (int i = 10; i >= 0; i--) {
		result = TPK(arr[i]);
		if (result > 400) {
			printf("Number #%d new value is bigger than 400!\n", i);
		} else {
			cout << "Number #" << i + 1 << " new value is: " << result << "\n";
		}			
		
	} 
	
	fb.close();
	
	return 0;
}