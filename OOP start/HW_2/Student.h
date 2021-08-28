class Student : public Person {
public:
	Student(std::string name, int age, double weight, bool isMale, int eduYear) :
		Person(name, age, weight, isMale), eduYear(eduYear), id(++studentsCount) {}
		
	void print() {
		std::cout << "Student id: " << id << "\n";
		Person::print();		
		std::cout << "Education year: " << eduYear << "\n\n";
	}
	
	Student& setEduYear(int eduYear) {
		this->eduYear = eduYear;
		return *this;
	}
	
	void increaseEduYear() {
		eduYear++;
	}
private:
	static int studentsCount;
	int eduYear;
	int id;
};
int Student::studentsCount = 0;