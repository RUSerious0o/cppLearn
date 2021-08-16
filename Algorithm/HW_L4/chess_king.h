//4.5
const int SIZE_X = 6;
const int SIZE_Y = 6;

enum FIGURE {OBSTACLE = -1, EMPTY = 0};
FIGURE ** field;

void initField() {
	field = (FIGURE**) calloc(sizeof(FIGURE*), SIZE_X);
	for(int i = 0; i < SIZE_X; i++) 
		*(field + i) = (FIGURE*) calloc(sizeof(FIGURE), SIZE_Y);		
}

int countRoutes(int x, int y) {
	if((x == 0 && y == 0) || 
		(x == 0 && field[x][y-1] == OBSTACLE) ||
		(y == 0 && field[x-1][y] == OBSTACLE)) return 0;	
	else if(field[x][y] == OBSTACLE) return -1;	
	else if(x == 0 ^ y == 0) return 1;
	else if(field[x-1][y] == OBSTACLE) return countRoutes(x, y - 1);
	else if(field[x][y-1] == OBSTACLE) return countRoutes(x - 1, y);
	else return countRoutes(x, y - 1) + countRoutes(x - 1, y);
}

void printField() {
	int temp;
	for(int i = 0; i < SIZE_X; i++) {
		for(int j = 0; j < SIZE_Y; j++) {
			temp = countRoutes(i, j);			
			if(temp == -1) printf("%4s", "-X");
			else printf("%4d", temp);
		}
		printf("\n");
	}
}

void setObstacle(int x, int y) {
	field[x][y] = OBSTACLE;
}

