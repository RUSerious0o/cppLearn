#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Fruits.h"
#include "BlackJack.h"

int main() {
	system("cls");
	// 2.1	
	std::vector<Student> students = {
		Student("Albert", 48, 91.7, true, 1),
		Student("Maria", 21, 45.2, false, 1),
		Student("Fred", 28, 103.5, true, 1)
	};
	
	students[2].print();	
	students[2].setEduYear(2).setName("Robert").setAge(32).setWeight(77.1);
	students[2].increaseEduYear();
	students[2].print();
	
	// 2.2
	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}