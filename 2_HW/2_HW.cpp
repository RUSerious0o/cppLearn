#include <iostream>
#include <vector>
#include <locale>
#include <fstream>

#include "../lib/Timer.cpp"
#include "TextAnalyser.cpp"

using namespace std;

//template <class T>
//void mySwap(T* const left, T* const right) {
//    T* const temp = *left;
//    left = right;
//    right = temp;
//}

template <class T>
void mySwap(T& left, T& right) {
    T temp = right;    
    *right = *left;
    *left = *temp;
}

void simpleSwap(int*& left, int*& right) {
    int* temp = right;
    right = left;
    left = temp;
}

void regularSwap(int& left, int& right) {
    int temp = right;
    right = left;
    left = temp;
}

int main() {
    system("cls");

    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_ALL, "Russian");

    { // 2.1
        pair<string*, string*> stringsToSwap = { new string("First string"), new string("Second string") };
        cout << stringsToSwap.first << " " << *stringsToSwap.first << endl;
        cout << stringsToSwap.second << " " << *stringsToSwap.second << endl;

        mySwap<string*>(stringsToSwap.first, stringsToSwap.second);
        cout << stringsToSwap.first << " " << *stringsToSwap.first << endl;
        cout << stringsToSwap.second << " " << *stringsToSwap.second << endl;

        delete stringsToSwap.first;
        delete stringsToSwap.second;

        {
            int* one = new int{ 15 };
            int* two = new int{ 30 };
            cout << one << " " << *one << " " << two << " " << *two << endl;
            simpleSwap(one, two);
            cout << one << " " << *one << " " << two << " " << *two << endl;
        }

        {
            int one{ 15 };
            int two{ 30 };
            cout << one << " " << &one << " " << two << " " << &two << endl;
            regularSwap(one, two);
            cout << one << " " << &one << " " << two << " " << &two << endl;
        }
    }

    // 2.2


    return 0;
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
