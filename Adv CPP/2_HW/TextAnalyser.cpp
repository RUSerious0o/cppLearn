#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class TextAnalyser {
public:

    // count_if + find
    unsigned long countVowel_countIf_find(const string& source) {
        return count_if(source.begin(), source.end(), [](char letter) {
            if (letters.find(letter) != string::npos) return true;
            return false;
            });;
    }

    // count_if + for
    unsigned long countVowel_countIf_for(const string& source) {
        return count_if(source.begin(), source.end(), MatchCondition());;
    }

    // for + find
    unsigned long countVowel_for_find(const string& source) {
        unsigned long result = 0;
        for (char c : source) {
            if (letters.find(c) != string::npos) ++result;
        }
        return result;
    }

    // 2 x for
    unsigned long countVowel_for_for(const string& source) {
        unsigned long result = 0;
        for (char c : source) {
            for (char l : letters) {
                if (c == l) ++result;
            }
        }
        return result;
    }

    void printPatterns() {
        for (char c : patterns) cout << c << ' ';
    }
private:
    static const vector<char> patterns;
    static const string letters;

    struct MatchCondition {
        bool operator() (const char& letter) {
            for (char c : patterns) {
                if (letter == c) return true;
            }
            return false;
        }
    };
};
const vector<char> TextAnalyser::patterns{ 'a', 'e', 'u', 'i', 'o',         // latin
        'à', 'ó', 'å', 'û', 'î', 'ý', 'ÿ', 'è', 'þ' };                      // ru
const string TextAnalyser::letters = "euioaóåûàîýÿèþ";