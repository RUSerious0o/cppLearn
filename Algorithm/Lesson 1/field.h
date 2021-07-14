typedef enum CellLetter {A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7} CellLetter;
typedef enum Sign {king = 'O', empty = '_', obstacle = 'X'} Sign;

const int FIELD_SIZE = 8;

class Cell {
	CellLetter letter;// = A;
	int number;// = 1;
	Sign sign;// = empty;
	
/*public:
	Cell() {
		
	}*/
public:
	Cell(CellLetter l, int n, Sign s) {
		letter = l;
		number = n;
		sign = s;
	}
};

class Field {
	Cell cells[FIELD_SIZE][FIELD_SIZE];
	
	/*Field() {
		for(int i = 0; i < FIELD_SIZE; i++) 
			for(int j = 0; j < FIELD_SIZE; j++)
				//std::cout << " |";
				cells[i][j] = new Cell(A , j, empty);
	}*/
	
	void init() {
		for(int i = 0; i < FIELD_SIZE; i++) 
			for(int j = 0; j < FIELD_SIZE; j++)
				cells[i][j] = new Cell((CellLetter) i, j, empty);
	}
};