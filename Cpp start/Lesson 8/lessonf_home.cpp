#include <iostream>
#include <random>
#include <fstream>
#include <filesystem> //C++17 cppreference.com

#define INSERT
#define THE_WORD "geekbrains"

//C++11
// #include <random>
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(65, 90);
//std::uniform_real_distribution<double> dist();

int getFileSize(const std::string& filename) {
	std::ifstream fis(filename, std::ifstream::ate);
	int size = fis.tellg();
	fis.close();
	return size;
}

std::string generateSymbols(int amount) {
  std::string result;
  for (int i = 0; i < amount; i++)
	{
		result.append(1, (char) dist(mt));
	}
  return result;
}

void writeFile(const std::string& filename, int length) {
  std::ofstream fos(filename);
  if (!fos) return;
  fos << generateSymbols(length);
  fos.close();
}

void writeFile(const std::string& filename, int length, int words) {
  std::ofstream fos(filename);
  for (int i = 0; i < words; i++)
	{
	  #ifdef INSERT
	  if (i != 0 && i % 3 == 0)
		fos << THE_WORD << " ";
	  else
	  #endif
	  fos << generateSymbols(length) << " ";
	}
  fos.close();
}

void concatenate(const std::string& from, const std::string& to) {
  std::ifstream fis(from);
  std::ofstream fos(to, std::ofstream::app);
  
  char c;
  while (fis.get(c) && !fis.eof()) {
	fos << c;
  }
  
  fis.close();
  fos.close();
}

void concatenate2(const std::string& from, const std::string& to) {
  std::ifstream fis(from);
  std::ofstream fos(to, std::ofstream::app);

  char* buffer = (char *)malloc(sizeof(char) * getFileSize(from));
  char c;
  int i = 0;
  while (fis.get(c) && !fis.eof()) {
	  *(buffer + i++) = c;
  }

  fos << buffer;

  delete buffer;
  //  free(buffer);
  
  fis.close();
  fos.close();
}

bool find(const std::string& filename, const std::string& word) {
  // char* wbytes = &word[0]; // old-fashion style
  std::ifstream fis(filename);
  if (!fis) {
	  std::cout << "no such file" << std::endl;
	  return 0;
  }
  const char* wbytes = word.c_str();

  char c;
  int step = 0;
  while (fis.get(c) && !fis.eof()) {
	if (c == *(wbytes + step)) {
	  step++;
	} else {
	  step = 0;
	  if (*wbytes == c) step++;     //geekgeekbrains
	}
	//гогоголь
	if (step == word.length())
	  return true;
  }
  return false;
}


int main(int argc, char** argv) {
	writeFile("hello1.txt", 50);
	writeFile("hello2.txt", 50);
	writeFile("search.txt", 10, 5);
	concatenate("hello1.txt", "hello3.txt");
	concatenate2("hello2.txt", "hello3.txt");

	if (argc < 2) {
		std::cout << "consider using arguments: program <filename> <word>" << std::endl;

		return 1;
	}

	std::cout << find(argv[1], argv[2]) << std::endl;
  
  
	return 0; 
}
