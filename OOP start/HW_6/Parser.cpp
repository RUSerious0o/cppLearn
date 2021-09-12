#include <fstream>
using namespace std;
class PseudoParser {
public:
	PseudoParser(string fileName) : 
		fileName(fileName),
		currencyTag("<span class='inline-stocks__value_inner'>"),
		weatherTag("<div class='weather__temp'>"),
		currency(new string[2]{"USD", "EUR"}) {}
		
	~PseudoParser() {
		delete [] currency;
	}
	
	void printExchangeRates() {
		if(!openFile()) return;
	
		string s;
		while(!file.eof()) {
			getline(file, s);
			
			for(int i = 0; i < CURRENCY_COUNT; i++) {
				string::size_type pos, posFrom, charactersCount;
				pos = s.find(currency[i]);
				if(pos != string::npos) {
					posFrom = s.find(currencyTag, pos) + currencyTag.size(); 
					charactersCount = s.find("<", posFrom) - posFrom;
					
					cout << currency[i] << " exchange rate: " << s.substr(posFrom, charactersCount) << endl;
				}
			}
			
		}
		file.close();
	}
	
	void printWeather() {
		if(!openFile()) return;
	
		string s;
		while(!file.eof()) {
			getline(file, s);
						
			string::size_type pos, posFrom, charactersCount;
			pos = s.find(weatherTag);
			if(pos != string::npos) {
				posFrom = pos + weatherTag.size(); 
				charactersCount = s.find("<", posFrom) - posFrom - 2;	// как отобразить ° в консоли - пока не придумал

				cout << "The weather is: " << s.substr(posFrom, charactersCount) << endl;
			}
		}
		file.close();
	}
private:
	const string fileName;
	const string currencyTag;
	const string weatherTag;
	const string * currency;
	const int CURRENCY_COUNT = 2;
	
	fstream file;
	
	bool openFile() {
		file.open(fileName, ios::in);		
		if(!file.is_open()) {
			cerr << "Open file failed!\n";
			return false;
		}
		
		return true;
	}
};