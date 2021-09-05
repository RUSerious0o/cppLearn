using namespace std;

int* convertKey(string key) {
	int* result = (int*) calloc(sizeof(int), key.size());
	
	int value;
	for(int i = 0; i < key.size(); i++) {
		if(i == 0) result[i] = 0;
		else {
			value = 0;
			for(int j = 0; j < i; j++) {
				if(key[i] > key[j]) value++;
				else result[j]++;
			}
			result[i] = value;
		}
	}
	
	return result;
}

void reverseKey(int* key, int size) {
	int temp[size] = {0};
	for(int i = 0; i < size; i++) 
		temp[key[i]] = i;
	
	for(int i = 0; i < size; i++)
		key[i] = temp[i];
}

string replacesEncrypt(string msg, string sKey) {
	if(msg.size() == 0 || sKey.size() == 0) return "";
	
	int msgSize = msg.size();
	int cols = sKey.size();
	int rows = msgSize % cols == 0 ? msgSize / cols : msgSize / cols + 1;
	char blank = ' ';
	char result[cols * rows];
	
	char crypt[rows][cols];
	int pos = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(i * cols + j >= msgSize) crypt[i][j] = blank;
			else crypt[i][j] = msg[pos++];
		}
	}
	
	int * key = convertKey(sKey);	
	pos = 0;
	for(int i = 0; i < sKey.size(); i++) {
		for(int j = 0; j < rows; j++) {
			result[pos++] = crypt[j][key[i]];
		}
	}
	result[pos] = '\0';
	
	
	free(key);		
	return result;
}

string replacesDecrypt(string msg, string sKey) {
	if(msg.size() == 0 || sKey.size() == 0) return "";
	
	int msgSize = msg.size();
	int cols = sKey.size();
	int rows = msgSize / cols;
	char result[cols * rows];
	
	char crypt[rows][cols];
	int pos = 0;
	for(int i = 0; i < cols; i++) {
		for(int j = 0; j < rows; j++) {
			crypt[j][i] = msg[pos++];
		}
	}
	
	int* key = convertKey(sKey);
	reverseKey(key, sKey.size());
	pos = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			result[pos++] = crypt[i][key[j]];
		}
	}
	result[pos] = '\0';
	
	free(key);
	return result;
}