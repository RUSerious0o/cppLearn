#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdarg>
using namespace std;

string fileNames[] = {"data_1.txt", "data_2.txt", "sum_data.txt"};
const int BUFFER_SIZE = 128;
const int MIN_FILE_SIZE = 50;
const int MAX_FILE_SIZE = 100;

void createFile(string, string = "");
void concatFiles(string, int, ...);
bool findWord(string, string);

int main(int argc, char ** argv) {
	// 6.1
	srand(time(nullptr));
	createFile(fileNames[0], " _EOF_1 ");
	createFile(fileNames[1]);
	
	// 6.2
	concatFiles(fileNames[2], 2, fileNames[0], fileNames[1]);
	
	// 6.3
	if(argc < 3) return 0;
	cout << "Word \"" << argv[1] << (findWord(argv[1], argv[2]) ? "\" found " : "\" not found ")
		<< "in file \"" << argv[2] << "\"";	
	
	return 0;
}

// 6.1
void createFile(string name, string eofMark) {	
	ofstream ofs(name, ofstream::out);
	int size = rand() % (MAX_FILE_SIZE - MIN_FILE_SIZE) + MIN_FILE_SIZE;
	char c;
	for(int i = 0; i < size; i++) 
		ofs << (c = rand() % 128 + 64);

	ofs << eofMark;
	ofs.close();
}

// 6.2
void concatFiles(string resultFileName, int fCount, ...) {
	char * buf = new char[BUFFER_SIZE];
	va_list list;
	ofstream ofs(resultFileName, ofstream::out);	
	va_start(list, fCount);
	for(int i = 0; i < fCount; i++) {	
		ifstream f(va_arg(list, string), ifstream::in);
		
		while(!f.eof()) {
			f.getline(buf, BUFFER_SIZE);
			ofs << buf;
		}
		f.close();
	}
	
	ofs.close();
	delete [] buf;
	va_end(list);
}

// 6.3
bool findWord(string word, string fileName) {
	ifstream f(fileName, ifstream::in);
	if(!f.is_open()) return false;
	
	bool result = false;
	string temp;	
	while(!f.eof()) {
		f >> temp;
		if(temp == word) {
			result = true;
			break;
		}
	}
	
	return result;
}