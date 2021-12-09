#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
#include <deque>
#include <map>

using namespace std;
const string FILE_NAME = "text.txt";

// 5.1
template <class T>
void printUniqueWords(T itBegin, T itEnd) {
	set<string> words;
	for (T it{ itBegin }; it < itEnd; ++it) {
		words.insert(*it);
	}

	copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
}

// 5.2
class SortedSentences {
public:
	SortedSentences(istream &source) {
		string text;
		getline(source, text);
		for (auto delim : { '.', '!', '?', '…' }) {		
			replace(text.begin(), text.end(), delim, '\n');
		}

		stringstream ss;
		ss << text;
		for (string sentence; getline(ss, sentence); ) {
			sentences.insert({sentence.size(), sentence});
		}		
	}

	void print() {
		for_each(sentences.rbegin(), sentences.rend(), [](pair<int, string> item) {
			cout << item.second << endl;
		});
	}
private:
	multimap<int, string> sentences;
};

int main(int argc, char** argv) {
	system("cls");

	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_ALL, "Russian");

	// 5.1
	ifstream file(FILE_NAME);
	if (!file.is_open()) {
		cout << "Can`t open file!";
		return 0;
	}

	vector<string> words;
	while (!file.eof()) {
		string s;
		file >> s;
		words.push_back(s);		
	}
	file.close();

	
	for (string &word : words) {		
		for(auto c : {',', '.', '\'', '`', '?', '!', '–', '…', '’'})
			word.erase(remove(word.begin(), word.end(), c), word.end());		
	}
	
	copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));

	cout << "\n\n";
	printUniqueWords(words.begin(), words.end());

	cout << "\n\n";
	deque<string> words_deque(words.begin(), words.end());
	printUniqueWords(words_deque.begin(), words_deque.end());
	cout << "\n\n";	

	// 5.2	
	file.open(FILE_NAME);
	SortedSentences(file).print();
	//SortedSentences(cin).print();			// also works

	return 0;
}