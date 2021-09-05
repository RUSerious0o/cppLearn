#include <iostream>
#include <string>
#include "../../../../mylib.h"
#include "caesar.h"
#include "replace.h"

using namespace std;

/*
	1.	Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
	2.	Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
*/

int main() {
	system("cls");
	// 16.1
	string msg = "SiVisPacemParaBellum";
	string encryptedMsg;
	int key = 3;
	cout << "Encrypted message: " << (encryptedMsg = caesarCrypt(msg, key)) << "\n";
	cout << "Decrypted message: " << caesarCrypt(encryptedMsg, -key) << "\n\n";
	
	key = -35;
	cout << "Encrypted message: " << (encryptedMsg = caesarCrypt(msg, key)) << "\n";
	cout << "Decrypted message: " << caesarCrypt(encryptedMsg, -key) << "\n\n";
	
	// 16.2
	msg = "HoustonWeHaveAProblem!!!!!!";
	string sKey = "Tower";
	cout << "Encrypted message: " << (encryptedMsg = replacesEncrypt(msg, sKey)) << "\n";
	cout << "Decrypted message: " << replacesDecrypt(encryptedMsg, sKey) << "\n\n";
	
	msg = "SiVisPacemParaBellum";
	sKey = "SuperVim";
	cout << "Encrypted message: " << (encryptedMsg = replacesEncrypt(msg, sKey)) << "\n";
	cout << "Decrypted message: " << replacesDecrypt(encryptedMsg, sKey) << "\n";
	
	return 0;
}