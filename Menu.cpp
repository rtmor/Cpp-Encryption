#include "Menu.h"//importing header file
//defining the constructor
Menu::Menu() {}

void Menu::mainMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "************************************************" << endl;
	cout << "* Welcome to the Encryption/Decryption Machine *" << endl;
	cout << "*                                              *" << endl;
	cout << "* Please select an option from the menu below  *" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	cout << "1) Encrypt text" << endl;
	cout << "2) Decrypt text" << endl;
	cout << "3) Exit" << endl;
	cout << "-> ";
	cin >> mainChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch (mainChoice) {
		case 1:
			Menu::encryptMenu();
			break;
		case 2:
			Menu::decryptMenu();
			break;
		case 3:
			return;
		default:
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << flush << endl;
			Menu::sleep();
			Menu::mainMenu();
	}
}
void Menu::encryptMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*                      Encryption                        *" << endl;
	cout << "*                                                        *" << endl;
	cout << "* Please choose an encryption method from the menu below *" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;

	cout << "1) Substitution Cipher" << endl;
	cout << "2) Transposition Cipher" << endl;
	cout << "3) Return to Main Menu" << endl;
	cout << "-> ";
	cin >> encryptChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch (encryptChoice) {
		case 1:
			Menu::enSubMenu();
			break;
		case 2:
			Menu::enCaeMenu();
			break;
		case 3:
			Menu::mainMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::encryptMenu();
			break;
	}
}
void Menu::decryptMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*                      Decryption                        *" << endl;
	cout << "*                                                        *" << endl;
	cout << "* Please choose a decryption method from the menu below  *" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;

	cout << "1) Substitution Cipher" << endl;
	cout << "2) Transposition Cipher" << endl;
	cout << "3) I don't know which decryption method was used" << endl;
	cout << "4) Return to Main Menu" << endl;
	cout << "-> ";
	cin >> decryptChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch (decryptChoice) {
		case 1:
			Menu::deSubMenu();
			break;
		case 2:
			Menu::deCaeMenu();
			break;
		case 3:
			Menu::bfMenu();
			break;
		case 4:
			Menu::mainMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::decryptMenu();
			break;
	}
}
string Menu::subEncrypt(string cleartext) {

	string ciphertext;

	for (int i{ 0 }; i <= cleartext.length(); i++) {
		for (int j{ 0 }; j < 26; j++) {
			if (cleartext[i] == ' ') {
				ciphertext += ' ';
				break;
			}
			if (cleartext[i] == alpha[j]) {
				ciphertext += subalpha[j];
				break;
			}
		}
	}
	return ciphertext;
}
string Menu::caesarEncrypt(string cleartext, int shift) {

	string ciphertext;

	for (int i{ 0 }; i <= cleartext.length(); i++) {
		for (int j{ 0 }; j < 26; j++) {
			if (cleartext[i] == ' ') {
				ciphertext += ' ';
				break;
			}
			if (cleartext[i] == alpha[j]) {
				caesarindex = (j + shift) % 26;
				ciphertext += alpha[caesarindex];
				break;
			}
		}
	}
	return ciphertext;
}
void Menu::enSubMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Encryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*        Substitution Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "1) Enter the text to be encrypted" << endl;
	cout << "2) Return to the Encryption Menu" << endl;
	cout << "-> ";
	cin >> enSubChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch(enSubChoice) {
		case 1: {
			cout << "\nEnter Clear Text" << endl;
			cin.ignore();
			getline(cin, cleartext);
			cout << "Encrypted message: " << Menu::subEncrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();
			break;
		}
		case 2:	
			Menu::encryptMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice " <<
				    "\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::enSubMenu();
			break;
	}
}
void Menu::enCaeMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Encryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*       Transposition Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "1) Enter the text to be encrypted" << endl;
	cout << "2) Return to the Encryption Menu" << endl;
	cout << "-> ";
	cin >> enCaeChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch(enCaeChoice) {
		case 1: {
			cout << "\nEnter Clear Text" << endl;
			cin.ignore();
			getline(cin, cleartext);
			cout << "Encrypted message: " << Menu::caesarEncrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();
			break;
		}
		case 2:
			Menu::encryptMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice " << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::enCaeMenu();
			break;
	}
}
string Menu::subDecrypt(string cleartext) {

	string ciphertext;

	for (int i{ 0 }; i < cleartext.length(); i++) {
		for (int j{ 0 }; j < 26; j++) {
			if (cleartext[i] == ' ') {
				ciphertext += ' ';
				break;
			}
			if (cleartext[i] == subalpha[j]) {
				ciphertext += alpha[j];
				break;
			}
		}
	}
	return ciphertext;
}
string Menu::caesarDecrypt(string cleartext, int shift) {

	string ciphertext;

	for (int i{ 0 }; i < cleartext.length(); i++) {
		for (int j{ 0 }; j < 26; j++) {
			if (cleartext[i] == ' ') {
				ciphertext += ' ';
				break;
			}
			if (cleartext[i] == alpha[j]) {
				caesarindex = (26 + j - shift) % 26;
				ciphertext += alpha[caesarindex];
				break;
			}
		}
	}
	return ciphertext;
}
void Menu::bruteforce(string ciphertext) {

	cout << endl;
	cout << left << setw(35) << "Caesar Brute Force" << "Substitution Brute Force" << endl;
	for (int shift{ 1 }; shift <= 26; shift++) {
		if (shift == 1) {
			cout << left << setw(35) << Menu::caesarEncrypt(ciphertext, shift);
			cout << Menu::subDecrypt(ciphertext) << endl;
			continue;
		}
		cout << left << setw(35) << Menu::caesarEncrypt(ciphertext, shift) << endl;
	}
}
void Menu::deSubMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*        Substitution Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "1) Enter the text to be decrypted" << endl;
	cout << "2) Return to the Decryption Menu" << endl;
	cout << "-> ";
	cin >> deSubChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch(deSubChoice) { 
		case 1:	{
			cout << "\nEnter Clear Text" << endl;
			cin.ignore();
			getline(cin, cleartext);
			cout << "Decrypted message: " << Menu::subDecrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();
			break;
		}
		case 2:
			Menu::decryptMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::deSubMenu();
			break;
	}
}
void Menu::deCaeMenu()
{
	Menu::clear_screen();
	int choice7{0};
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*       Transposition Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "1) Enter the text to be decrypted" << endl;
	cout << "2) Return to the decryption Menu" << endl;
	cout << "-> ";
	cin >> deCaeChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch(deCaeChoice)	{
		case 1: {
			cout << "\nEnter Clear Text" << endl;
			cin.ignore();
			getline(cin, cleartext);
			cout << "Decrypted message: " << Menu::caesarDecrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();
			break;
		}
		case 2:
			Menu::decryptMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Again" << endl;
			Menu::sleep();
			Menu::deCaeMenu();
			break;
	}
}
void Menu::bfMenu()
{
	Menu::clear_screen();
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*          Unknown Cipher           *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "1) Attempt to decrypt using a bruteforce method" << endl;
	cout << "2) Return to the decryption Menu" << endl;
	cout << "-> ";
	cin >> bfChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch(bfChoice)	{
		case 1: {
			cout << "\nEnter Clear Text" << endl;
			cin.ignore();
			getline(cin, cleartext);
			Menu::bruteforce(cleartext);
			cout << endl;
			Menu::superMenu();
			break;
		}
		case 2:
			Menu::decryptMenu();
			break;
		default:
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Agagin" << endl;
			Menu::sleep();
			Menu::bfMenu();
			break;
	}
}
void Menu::superMenu()
{
	cout << endl;
	cout << "***************************" << endl;
	cout << "*   Please choose where   *" << endl;
	cout << "* you'd like to return to *" << endl;
	cout << "*   from the menu below   *" << endl;
	cout << "***************************" << endl;
	cout << endl;

	cout << "1) Encryption Menu" << endl;
	cout << "2) Decryption Menu" << endl;
	cout << "3) Main Menu" << endl;
	cout << "-> ";
	cin >> superChoice;
	if(!cin) {
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // the first parameter is just some arbitrarily large value, the second param being the character to ignore till 
	}
	switch (superChoice) {
	case 1:
		Menu::encryptMenu();
		break;
	case 2:
		Menu::decryptMenu();
		break;
	case 3:
		Menu::mainMenu();
		break;
	default:
		cout << endl;
		cout << "Invalid Choice" <<
				"\nPlease Choose Again" << endl;
		Menu::sleep();
		Menu::superMenu();
		break;
	}
}

void Menu::clear_screen() {
	#ifdef WINDOWS
	    std::system("cls");
	#elif _WIN32
		std::system("cls");
	#elif _WIN64
		std::system("cls");
	#else
	    // Assume POSIX
	    std::system ("clear");
	#endif
}

void Menu::sleep() {
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    sleep_for(1s);
}
