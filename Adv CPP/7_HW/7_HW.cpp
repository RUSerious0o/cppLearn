#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <fstream>

using std::string;
using std::vector;
using std::cout;

class FullName {
public:
	FullName(string name, string lastName, string patronymic = "") :
		name(name), lastName(lastName), patronymic(patronymic) {
	};

	string toString() const {
		std::stringstream ss;
		ss << name << " " << lastName;
		if (patronymic == "") ss << " -";
		else ss << " " << patronymic;
		return ss.str();
	}

	friend std::ostream& operator<<(std::ostream&, const FullName&);
private:
	string name;
	string lastName;
	string patronymic;

	static constexpr int FIELD_WIDTH = 14;
};

std::ostream& operator<<(std::ostream& out, const FullName& fullName) {
	out.width(FullName::FIELD_WIDTH);
	out << fullName.name;
	out.width(FullName::FIELD_WIDTH);
	out << fullName.patronymic;
	out.width(FullName::FIELD_WIDTH); 
	out << fullName.lastName;
	return out;
}

class Student {
public:
	Student(const FullName& fullName, const vector<int>& grades = {0}) :
		fullName(fullName), grades(grades) {
	}

	const FullName& getFullName() const {
		return fullName;
	}

	double getAverageGrade() const {
		return static_cast<double>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
	}

	const vector<int>& getGrades() const {
		return grades;
	}

	friend std::ostream& operator<<(std::ostream&, const Student&);
	bool operator==(const Student& other) {
		return fullName.toString() == other.getFullName().toString();
	}
private:
	FullName fullName;
	vector<int> grades;	
};

std::ostream& operator<<(std::ostream& out, const Student& student) {
	out << student.fullName << ": ";
	std::copy(student.grades.begin(), student.grades.end(), std::ostream_iterator<int>{ out, ", " });
	out.precision(2);
	out << std::fixed << "avg : " << student.getAverageGrade();
	return out;
}

class IRepository {
public:
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
public:
	virtual double GetAverageScore(const FullName& name) = 0;
	virtual string GetAllInfo(const FullName& name) = 0;
	virtual string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods {
public:
	void add(const Student& student) {
		students.push_back(student);
	}

	void Open() override {
		std::ifstream in(DATA_FILE_NAME, std::ios::binary);
		while (!in.eof()) {
			string line;
			std::getline(in, line);

			if (line == "") break;

			std::stringstream ss;
			ss << line;

			string name, lastName, patronymic;
			ss >> name;
			ss >> lastName;
			ss >> patronymic;
			if (patronymic == "-") patronymic = "";

			int grade;
			vector<int> grades;
			while (!ss.eof()) {
				ss >> grade;
				grades.push_back(grade);
			}
			
			add({ {name, lastName, patronymic}, grades });
		}
	}

	void Save() override {
		std::ofstream out(DATA_FILE_NAME, std::ios::binary);
		out << toString();
	}

	double GetAverageScore(const FullName& fullName) override {
		auto it = std::find(students.begin(), students.end(), Student{ fullName });
		if (it == students.end()) return 0.0;
		return (*it).getAverageGrade();
	}

	string GetAllInfo(const FullName& fullName) override {
		auto it = std::find(students.begin(), students.end(), Student{ fullName });
		if (it == students.end()) return "Student not found!";
		return (*it).getFullName().toString();		
	}

	string GetAllInfo() override {
		std::stringstream ss;
		for (Student student : students) {
			ss << student << std::endl;
		}
		return ss.str();
	}
private:
	vector<Student> students;

	string DATA_FILE_NAME = "data.bin";

	string toString() {
		if (students.size() == 0) return "";

		std::stringstream ss;
		for (Student student : students) {
			ss << student.getFullName().toString();
			for (int grade : student.getGrades()) {
				ss << " " << grade;
			}
			ss << std::endl;
		}		
		return ss.str();
	}
};

int main(int argc, char** argv) {
	StudentsGroup group;
	for (Student student : {
		Student{ { "Mike","Vazovski" }, { 3,4,5,3 } },
		Student{ { "John","Smith" }, { 5,4,5 } },
		Student{ { "Oleg","Korolev", "Vasil`evich" }, { 5,4,4 } },
		Student{ { "Maria","Kane" }, { 3,4,2 } },
		Student{ { "Jessica","Jones" }, { 3,4,3 } },
		Student{ { "Monica","Belucci" } },
	}) {
		group.add(student);
	}

	cout << group.GetAllInfo() << std::endl << group.GetAllInfo({ "Mike","Vazovski" }) << " " << group.GetAverageScore({ "Mike","Vazovski" }) << std::endl;
	cout << group.GetAllInfo({ "Oleg","Korolev", "Vasil`evich" }) << "\n\n";

	group.Save();

	StudentsGroup newGroup;
	newGroup.Open();
	cout << newGroup.GetAllInfo();

	return 0;
}