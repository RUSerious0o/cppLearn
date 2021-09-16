#include "GenericPlayer.cpp"

/*
3.	Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
●	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
●	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
●	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
●	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

using namespace std;
class Player : public GenericPlayer {
public:
	Player(string name) : GenericPlayer(name) {}

	virtual bool isHitting() const override {
		bool result = false;
		do {
			char c;
			cout << "Do you want another card? ";
			cin >> setw(1) >> c;

			if (c == 'Y' || c == 'y') {
				result = true;
				break;
			}
			else if (c == 'N' || c == 'n') break;

			cout << "Your answear is anclear. ";
		} while (true);
		return result;
	}

	void win() {
		cout << "Congratulations, " << getName() << ", you won!\n";
	}

	void lose() {
		cout << "Sorry, " << getName() << ", you lose!\n";
	}

	void push() {
		cout << "Player " << getName() << " pushed!\n";
	}
private:
	
};