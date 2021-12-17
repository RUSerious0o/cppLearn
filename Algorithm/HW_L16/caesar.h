using namespace std;

string caesarCrypt(string s, int key) {
	if(s.size() == 0) return "";
	
	const int LETTERS_COUNT = 26;
	char upper[LETTERS_COUNT];
	char lower[LETTERS_COUNT];
	
	key = key % LETTERS_COUNT;
	if(key < 0) key += LETTERS_COUNT;
	
	for(int i = 'A'; i <= 'Z'; i++)
		upper[i - 'A'] = i;
	for(int i = 'a'; i <= 'z'; i++)
		lower[i - 'a'] = i;
	
	
	char c;
	char encrypted[s.size()];
	int pos = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {		
			encrypted[pos++] = upper[(s[i] - 'A' + key) % LETTERS_COUNT];
			continue;
		}
		
		if(s[i] >= 'a' && s[i] <= 'z') {		
			encrypted[pos++] = lower[(s[i] - 'a' + key) % LETTERS_COUNT];			
		}		
	}
	encrypted[pos] = '\0';
	return encrypted;
}