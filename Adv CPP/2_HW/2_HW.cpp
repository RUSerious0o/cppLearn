#include <iostream>
#include <vector>
#include <locale>
#include <fstream>

#include "../lib/Timer.cpp"
#include "TextAnalyser.cpp"

using namespace std;

// 2.1
template <class T>
void mySwap(T& left, T& right) {
    T temp = right;    
    right = left;
    left = temp;
}

// 2.2
template <class T>
void printVector(vector<T>& v) {
    for (T item : v) cout << item << " ";
    cout << endl;
}

template<class T>
class PointerSorter {
public:
    PointerSorter(vector<T> &values) {
        for (int i = 0; i < values.size(); i++) {
            pointers.push_back(&values[i]);
        }
    }

    void sortPointers() {
        sort(pointers.begin(), pointers.end(), PointersComparator());
    }

    void printPointerValues() {
        for (T* item : pointers) cout << *item << " ";
        cout << endl;
    }

private:
    vector<T*> pointers;

    struct PointersComparator {
        bool operator() (T*& left, T*& right) {
            return *left < *right;
        }
    };
};

int main() {
    system("cls");

    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_ALL, "Russian");

    { // 2.1
        pair<string*, string*> stringsToSwap = { new string("First string"), new string("Second string") };
        cout << &stringsToSwap.first << " " << stringsToSwap.first << " " << *stringsToSwap.first << endl;
        cout << &stringsToSwap.second << " " <<stringsToSwap.second << " " << *stringsToSwap.second << endl;

        mySwap<string*>(stringsToSwap.first, stringsToSwap.second);
        cout << &stringsToSwap.first << " " << stringsToSwap.first << " " << *stringsToSwap.first << endl;
        cout << &stringsToSwap.second << " " << stringsToSwap.second << " " << *stringsToSwap.second << endl;

        delete stringsToSwap.first;
        delete stringsToSwap.second;
        cout << endl;
    }

    // 2.2
    {
        vector<string> values{ "Bob", "Mike", "Ann", "Alex", "John", "Sergey" };
        PointerSorter<string> pointers(values);

        printVector<string>(values);
        pointers.printPointerValues();
        cout << endl;

        pointers.sortPointers();
        printVector<string>(values);
        pointers.printPointerValues();
        cout << endl;
    }


    // 2.3
    TextAnalyser analyser;
    Timer timer;

    ifstream file{ "../../../War and peace 1.txt" };
    if (!file.is_open()) return 0;
        
    file.seekg(0, ios::end);
    size_t size = file.tellg();
    file.seekg(0);
    string temp(size, ' ');
    file.read(&temp[0], size);

    vector<string> sourceStrings{ "Some looooooong string", "Русская строка", "Смешанная string aaa", move(temp) };
    
    cout << "Гласные: "; analyser.printPatterns(); cout << endl;

    int caseCounter = 0;
    for (unsigned long (TextAnalyser:: * m) (const string&) : 
        {&TextAnalyser::countVowel_countIf_for, 
        &TextAnalyser::countVowel_countIf_find,
        &TextAnalyser::countVowel_for_find,
        &TextAnalyser::countVowel_for_for}) {
            cout << endl;
            timer.start("Elapsed time: ");
            for (string s : sourceStrings) {            
                cout.width(25);
                if (s.size() < 24) {
                    cout << s;
                }
                else {
                    cout << "Война и мир, 1 том";
                }
                cout << ": гласных - " << (analyser.*m)(s) << endl;
            }
            timer.print();
        }

    return 0;
}
