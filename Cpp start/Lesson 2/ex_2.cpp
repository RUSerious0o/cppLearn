#include <iostream>

int main() {
	// 2.1 variables
	int i = 17;
	char c = 28;
	long j = 222466685;
	float f = 1.23;
	double z = 5.546519681521;
	bool flag = true;
	
	//printf("%.15f\n", z);
	
	// 2.2 enumeration
	enum valuesXO {undefined, cross, zero};
	using ValuesXO = enum valuesXO;
	
	// 2.3 array
	ValuesXO arr[] = {cross, zero, cross};
	
	// 2.4 struct
	struct fieldXO {
		ValuesXO positionValue[3][3] = {undefined};
	};
	using FieldXO = struct fieldXO;
	
	FieldXO field;
	field.positionValue[1][1] = cross;
	field.positionValue[1][0] = zero;
	std::cout << field.positionValue[1][1] << " ";
	std::cout << field.positionValue[1][0] << " ";
	std::cout << field.positionValue[0][0] << std::endl;
	
	// 2.5 union
	struct myVar {
		int isInt : 1;
		int isFloat : 1;
		int isChar : 1;
		
		union varValue {
			int i;
			float f;
			char c;
		};
		union varValue value;		
	};
	using MyVar = struct myVar;
	
	MyVar v;
	v.value.i = 78;
	v.isInt = 1;
	v.isFloat= 0;
	v.isChar = 0;
	
	if(v.isInt) std::cout << v.value.i << std::endl;	
	
	return 0;
}