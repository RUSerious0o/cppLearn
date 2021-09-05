/*
4.	Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
●	IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
●	IsBoosted() - возвращает bool значение, есть ли у игрока перебор
●	Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/

#ifndef BJ_GENERIC_PLAYER
#define BJ_GENERIC_PLAYER

#include "Hand.cpp"

using namespace std;

class GenericPlayer : public Hand {
public:
	GenericPlayer(string name) : name(name) {}
	
	string getName() const { return name; }
	
	//virtual bool isHitting() = 0;
	
	bool isBoosted() {
		if(getTotal() > 21) return true;
		return false;
	}
	
	void boost() {
		if(isBoosted())
			cout << "Player: " << name << " is boosted!\n";
	}
private:
	string name;
};

#endif