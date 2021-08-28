class Person {
public:
	Person(std::string name, int age, double weight, bool isMale) :
		name(name), age(age), weight(weight), isMale(isMale) {}
	
	virtual void print() const {
		std::cout 	<< "Name: " << name << "\n" 
				<< "Age: " << age << "\n" 
				<< "Weight: " << weight << "\n" 
				<< "Gender: " << (isMale ? "male" : "female")<< "\n";
	}
	
	Person& setName(std::string name) {
		this->name = name;
		return *this;
	}
	
	Person& setAge(int age) {
		this->age = age;
		return *this;
	}
	
	Person& setWeight(double weight) {
		this->weight = weight;
		return *this;
	}
private:
	std::string name;
	int age;
	double weight;
	bool isMale;
};