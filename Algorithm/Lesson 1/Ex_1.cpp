/* start 21.25	
	21.53 - засада. 
	21.55 - reboot:
	struct Position
	
	bool positionIsOccutied()
	bool lineHasObstackle()
	printField()
	moveTo()
	void generateObstacles() //lines 2-7, int count
	
	Position kingPosition = D8
	Position obstaclePosition[]
	Position startPosition
	Position targetPosition
	Position previousPosition
	Position moveMatrix[8];
	float distance
	float minDistance
	int moveDirectionId
	
	
	План-капкан:
	Короля устанавливаем в "доме" верхней позиции
	"Цель" устанавливаем на 1 линии, скажем в углу (например)
	в исходные данные запиливаем несколько наборов "препятствий", выбираем случайный из них
	ходим (3) раза в секунду
	На каждый ход просчитываем все незанятые клетки вокруг текущей, кроме той, откуда пришли:
	distance = 1000;
	for_each(step in moveMatrix)
	if(!positionIsOccutied) distance = distance < getDistance() ? ...
	короче определяем moveDirectionId
	
	повторить 140 раз, пока не дойдем до цели. 
	
	Мысль номер "еще раз":
	Можно пойти от обратного:
	1. Создать поле;
	2. Каждой клетке поля присвоить значение из перечисления {king='O', empty='_', obstacle='X'}
	3. 
*/
#include <iostream>

using namespace std;

/*enum Letter {A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7};


struct Position {
	Letter letter;
	int number;
};

void printField();

Position obstaclePosition[5];
Letter oLetters[5] = {C,D,E,E,C};
int oNumbers[5] = {2,2,3,4,6};

void printField() { 
	system("cls");
	printf("   A B C D E F G H\n");
	for(int i = 0; i < 8; i++) {
		printf("%i |", i+1);
		for(int j = 0; j < 8; j++) {
			printf("%c|", empty);
		}
		cout << "\n";
	}
} */

#include "field.h"

int main(int argc, char ** argv) {
	
	
	return 0;
}

