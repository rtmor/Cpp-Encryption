/*
Daniel Gaska
Ryan Moran
Elisabeth Brooks
Anthony Scalise

C++ Encryption/Decryption Project
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Menu//creating the class
{
public://public member function prototypes

	//creating protoype functions
	Menu();
	void mainMenu();
	void encryptMenu();
	void decryptMenu();
	string subEncrypt(string);
	string caesarEncrypt(string, int shift=14);
	void enSubMenu();
	void enCaeMenu();
	string subDecrypt(string);
	string caesarDecrypt(string, int shift=14);
	void bruteforce(string);
	void deSubMenu();
	void deCaeMenu();
	void bfMenu();
	void superMenu();
	void clear_screen();
	void sleep();

private://private data members
	int mainChoice{ 0 };
	int encryptChoice{ 0 };
	int decryptChoice{ 0 };
	int enSubChoice{ 0 };
	int enCaeChoice{ 0 };
	int deSubChoice{ 0 };
	int deCaeChoice{ 0 };
	int bfChoice{ 0 };
	int superChoice{ 0 };
	int caesarindex;
	int subindex;
	string cleartext;
	string alpha = "kfleyinjxrawdchvumtqzpsgob";
	string subalpha = "moswlfxtecbjnypzkgqudhvria";
};//end class Menu