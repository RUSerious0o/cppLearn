class Fruit {
public:
	Fruit(std::string name, std::string color) : name(name), color(color) {}
	
	std::string getName() { return name; }
	
	std::string getColor() { return color; }
protected:
	std::string name;
	std::string color;
};

class Apple : public Fruit {
public:
	Apple(std::string color) : Fruit("apple", color) {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("green") {}
	
	std::string getName() { 
		return "GrannySmith " + name;
	}	
};

class Banana : public Fruit {
public:
	Banana() : Fruit("banana", "yellow") {}	
};