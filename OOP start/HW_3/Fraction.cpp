/*
3.	Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
●	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
●	унарный оператор (-)
●	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 

*/
using namespace std;

class Fraction {
public:
	Fraction(int divident, int divider) : divident(divident), divider(divider == 0 ? 1 : divider) {
		if(divider == 0) 
			cout << "Warning! Divider must be more or less than 0! Replaced by 1.";
	}
	
	Fraction operator+ (Fraction& fr) {
		int dTop, dBot;
		if(fr.divider != divider) dBot = fr.divider * divider;
		else dBot = divider;
		
		dTop = divident * dBot / divider + fr.divident * dBot / fr.divider;
		
		return Fraction(dTop, dBot);
	}
	
	Fraction operator- (Fraction& fr) {
		int dTop, dBot;
		if(fr.divider != divider) dBot = fr.divider * divider;
		else dBot = divider;
		
		dTop = divident * dBot / divider - fr.divident * dBot / fr.divider;
		
		return Fraction(dTop, dBot);
	}
	
	Fraction operator* (Fraction& fr) {
		return Fraction(fr.divident * divident, fr.divider * divider);
	}
	
	Fraction operator/ (Fraction& fr) {
		return Fraction(divident * fr.divider, divider * fr.divident);
	}
	
	bool operator== (Fraction& fr) {
		double dif = (double) divident / divider - (double) fr.divident / fr.divider;
		if(dif < 0) dif = -dif;
		if(dif < 0.000000001) return true;
		return false;
	}
	
	bool operator!= (Fraction& fr) {
		return !(*this == fr);
	}
	
	bool operator> (Fraction& fr) {
		return((double) divident / divider > (double) fr.divident / fr.divider);
	}
	
	bool operator<= (Fraction& fr) {
		return !(*this > fr);
	}
	
	bool operator< (Fraction& fr) {
		return((double) divident / divider < (double) fr.divident / fr.divider);
	}
	
	bool operator>= (Fraction& fr) {
		return !(*this < fr);
	}
	
	Fraction operator- () {
		return Fraction(-divident, divider);
	}
	
	void print() { cout << divident << " / " << divider << endl; }
private:
	int divident;
	int divider;
};