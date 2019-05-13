#include "Menu.h"//importing header file

// defining the constructor
Menu::Menu() {}

// main menu member function
void Menu::mainMenu()
{
	Menu::clear_screen(); //clears screen before menu call
	cout << endl;
	cout << "************************************************" << endl;
	cout << "* Welcome to the Encryption/Decryption Machine *" << endl;
	cout << "*                                              *" << endl;
	cout << "* Please select an option from the menu below  *" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	// Prompt user for main menu selection
	cout << "1) Encrypt text" << endl;
	cout << "2) Decrypt text" << endl;
	cout << "3) Exit" << endl;
	cout << "-> ";
	cin >> mainChoice;
	if(!cin) {        // if input does not match data type
		cin.clear(); // clears error flags
 		cin.ignore(999,'\n'); // ignore all input up until new line
	}
	switch (mainChoice) {
		case 1:
			Menu::encryptMenu(); // call encryption main menu
			break;
		case 2:
			Menu::decryptMenu(); // call decryption main menu
			break;
		case 3: 		// exit program
			return;
		default:		// handles out of range requests
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << flush << endl;
			Menu::sleep();  // call sleep function to review error prior to mainmenu call (clearing screen)
			Menu::mainMenu();  // return to main menu
	}
}
void Menu::encryptMenu()  // main encryption menu
{
	Menu::clear_screen();  // call clearscreen
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*                      Encryption                        *" << endl;
	cout << "*                                                        *" << endl;
	cout << "* Please choose an encryption method from the menu below *" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;

	// prompt user for encryption selection
	cout << "1) Substitution Cipher" << endl;
	cout << "2) Transposition Cipher" << endl;
	cout << "3) Return to Main Menu" << endl;
	cout << "-> ";
	cin >> encryptChoice;
	if(!cin) {			// check for invalid data types
		cin.clear();				// clears error flags
 		cin.ignore(999,'\n');		// ignore input buffer to newline
	}
	switch (encryptChoice) {
		case 1:
			Menu::enSubMenu();  	// call substitution encryption submenu
			break;
		case 2:
			Menu::enCaeMenu();  	// call transposition encryption submenu 
			break;
		case 3:
			Menu::mainMenu();   	// return to main menu
			break;
		default:				// handle all input out of range
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Again" << endl;
			Menu::sleep();				// call sleep function to delay return to encrypt menu 
			Menu::encryptMenu();
			break;
	}
}
// Main decryption menu
void Menu::decryptMenu()  		
{
	Menu::clear_screen();			// call clear screen
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*                      Decryption                        *" << endl;
	cout << "*                                                        *" << endl;
	cout << "* Please choose a decryption method from the menu below  *" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Substitution Cipher" << endl;
	cout << "2) Transposition Cipher" << endl;
	cout << "3) I don't know which decryption method was used" << endl;
	cout << "4) Return to Main Menu" << endl;
	cout << "-> ";
	cin >> decryptChoice;
	if(!cin) {					// check for invalid data types
		cin.clear();				// clears error flags
 		cin.ignore(999,'\n');		// ignore input buffer to newline
	}
	switch (decryptChoice) {
		case 1:
			Menu::deSubMenu();		// call substitution decryption submenu
			break;
		case 2:
			Menu::deCaeMenu(); 		// call transposition decryption submenu
			break;
		case 3:
			Menu::bfMenu();		// call bruteforce decryption submenu
			break;
		case 4:
			Menu::mainMenu();		// return to main menu
			break;
		default:				// handle all input out of range
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();			// call sleep function to delay return to decrypt menu
			Menu::decryptMenu();
			break;
	}
}

// Substitution encryption function
string Menu::subEncrypt(string cleartext) {

	string ciphertext;

	for (int i{ 0 }; i <= cleartext.length(); i++) {  	// for char in cleartext
		for (int j{ 0 }; j < 26; j++) {			// for char in alpha
			if (cleartext[i] == ' ') {			// check for whitespace character
				ciphertext += ' ';
				break;
			}
			if (toupper(cleartext[i]) == toupper(alpha[j])) {	// translate cleartext char to upper & match w/ upper char
				if (isupper(cleartext[i])) {					// if cleartext char is uppercase
					ciphertext += toupper(subalpha[j]);			// add respective uppercase substitution char to cipher
					break;
				}
				else {								// if char is lowercase
					ciphertext += subalpha[j];		// add respective lowercase substitution char to cipher
					break;
				}
			}
		}
	}
	return ciphertext;			// return ciphertext to calling function
}
// Transposition encryption function
string Menu::caesarEncrypt(string cleartext, int shift) {

	string ciphertext;

	for (int i{ 0 }; i <= cleartext.length(); i++) {	// for char in cleartext
		for (int j{ 0 }; j < 26; j++) {			// for char in ciphertext
			if (cleartext[i] == ' ') {			// if cleartext char is whitespace
				ciphertext += ' ';				// add whitespace to ciphertext
				break;
			}
			if (toupper(cleartext[i]) == toupper(alpha[j])) {	// translate cleartext char to upper & match w/ upper alpha char
				if (isupper(cleartext[i])) {		// if cleartext char is upper
					caesarindex = (j + shift) % 26;		// shift index
					ciphertext += toupper(alpha[caesarindex]);	// add shifted uppercase char to cipher text
					break;
				}
				else {							        // if cleartext char is lower
					caesarindex = (j + shift) % 26;		// shift index
					ciphertext += alpha[caesarindex];	// add shifted lowercase char to cipher text
					break;
				}
			}
		}
	}
	return ciphertext;		// return ciphertext to calling function
}
// Substitution encryption menu
void Menu::enSubMenu()
{
	Menu::clear_screen(); 	// call clear screen
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Encryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*        Substitution Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Enter the text to be encrypted" << endl;
	cout << "2) Return to the Encryption Menu" << endl;
	cout << "-> ";
	cin >> enSubChoice;
	if(!cin) {				// if input does not match data type
		cin.clear(); 		// clears error flags
 		cin.ignore(999,'\n'); 		// ignore input buffer to newline
	}
	switch(enSubChoice) {
		case 1: {
			cout << "\nEnter Clear Text" << endl;		// prompt user for cleartext			
			cin.ignore();			// clear input buffer
			getline(cin, cleartext);	// store input
			// return substitution encrypted text
			cout << "Encrypted message: " << Menu::subEncrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();		// call main submenu
			break;
		}
		case 2:	
			Menu::encryptMenu();	// return to encryption menu
			break;
		default:
			cout << endl;		// check for input out of range
			cout << "Invalid Choice " <<
				    "\nPlease Choose Again" << endl;
			Menu::sleep();		// add error delay prior to calling top of function
			Menu::enSubMenu();		// call top of function
			break;
	}
}
// Transposition encryption submenu
void Menu::enCaeMenu()
{
	Menu::clear_screen();	// clear screen
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Encryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*       Transposition Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Enter the text to be encrypted" << endl;
	cout << "2) Return to the Encryption Menu" << endl;
	cout << "-> ";
	cin >> enCaeChoice;
	if(!cin) {				// if input does not match data type
		cin.clear(); 		// clears error flags
 		cin.ignore(999,'\n'); 	// ignore input buffer to newline
	}
	switch(enCaeChoice) {
		case 1: {
			cout << "\nEnter Clear Text" << endl;	// prompt user for cleartext
			cin.ignore();				// clear input buffer
			getline(cin, cleartext);	// save cleartext input
			// return caesar encrypted cleartext
			cout << "Encrypted message: " << Menu::caesarEncrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();		// call main submenu
			break;
		}
		case 2:
			Menu::encryptMenu();	// return to top of encryption menu
			break;
		default:			// if input is out of range
			cout << endl;
			cout << "Invalid Choice " << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();			// delay for error message return to top of menu
			Menu::enCaeMenu();		// call top of menu
			break;
	}
}
// Substitution decryption function
string Menu::subDecrypt(string cleartext) {

	string ciphertext;

	for (int i{ 0 }; i < cleartext.length(); i++) {   // for char in ciphertext
		for (int j{ 0 }; j < 26; j++) {		// for char in subalpha
			if (cleartext[i] == ' ') {		// if char is whitespace
				ciphertext += ' ';			// add whitespace to 'cleartext'
				break;
			}
			// if upper 'ciphertex' char matches upper subalpha char
			if (toupper(cleartext[i]) == toupper(subalpha[j])) {
				if (isupper(cleartext[i])) {		// check if ciphertext char is upper
					ciphertext += toupper(alpha[j]);	// add respective upper alpha char to 'cleartext'
					break;
				}
				else {					// if ciphertext char is lower
					ciphertext += alpha[j];		// add respective lower alpha char to 'cleartext'
					break;
				}
			}
		}
	}
	return ciphertext;			// return cleartext to calling function
}
// Transposition decryption function
string Menu::caesarDecrypt(string cleartext, int shift) {

	string ciphertext;

	for (int i{ 0 }; i < cleartext.length(); i++) {		// for char in ciphertext
		for (int j{ 0 }; j < 26; j++) {			// for char in alpha
			if (cleartext[i] == ' ') {			// if ciphertext char is whitespace
				ciphertext += ' ';				// add whitespace to ciphertext
				break;
			}
			// if upper cipher matches upper alpha
			if (toupper(cleartext[i])== toupper(alpha[j])) {
				if (isupper(cleartext[i])) {				// if cipher char is upper
					caesarindex = (26 + j - shift) % 26;	// subtract index shift
					// add respective shifted upper char to 'cleartext'
					ciphertext += toupper(alpha[caesarindex]);
					break;
				}
				else {										// if cipher char is lower
					caesarindex = (26 + j - shift) % 26;	// subtract index shift
					ciphertext += alpha[caesarindex];		// add respective shifted lower char to 'cleartext'
					break;
				}
			}
		}
	}
	return ciphertext;				// return 'cleartext' to calling function
}
// Brute force function - returns all 26 shifted values and substitution decrypt attempt
void Menu::bruteforce(string ciphertext) {

	cout << endl;
	cout << left << setw(35) << "Caesar Brute Force" << "Substitution Cipher" << endl;
	for (int shift{ 1 }; shift <= 26; shift++) {	// for each of 26 shifts
		if (shift == 1) {							// if first iteration
			// include first transposition offset
			cout << left << setw(35) << Menu::caesarEncrypt(ciphertext, shift);
			// as well as substitution decryption attempt
			cout << Menu::subDecrypt(ciphertext) << endl;
			continue;
		}
		// return remaining transpotition offsets
		cout << left << setw(35) << Menu::caesarEncrypt(ciphertext, shift) << endl;
	}
}
// Substitution decrypt submenu
void Menu::deSubMenu()
{
	Menu::clear_screen();			// clear screen
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*        Substitution Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Enter the text to be decrypted" << endl;
	cout << "2) Return to the Decryption Menu" << endl;
	cout << "-> ";
	cin >> deSubChoice;
	if(!cin) {						// if input invalid data type
		cin.clear(); 				// clears error flags
 		cin.ignore(999,'\n'); 		// ignore input buffer to newline
	}
	switch(deSubChoice) { 
		case 1:	{
			cout << "\nEnter Clear Text" << endl;  // prompt user for ciphertext
			cin.ignore();						   // clear input buffer
			getline(cin, cleartext);			// save ciphertext
			// return substitution decrypted cipher text
			cout << "Decrypted message: " << Menu::subDecrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();			// call main submenu
			break;
		}
		case 2:
			Menu::decryptMenu();		// return to decrypt menu
			break;
		default:						// if input is out of range
			cout << endl;
			cout << "Invalid Choice" << 
					"\nPlease Choose Again" << endl;
			Menu::sleep();				// delay return to top for error message
			Menu::deSubMenu();			// return to top of function
			break;
	}
}
// Transposition decryption menu
void Menu::deCaeMenu()
{
	Menu::clear_screen();			// clear screen
	int choice7{0};
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*       Transposition Cipher        *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Enter the text to be decrypted" << endl;
	cout << "2) Return to the decryption Menu" << endl;
	cout << "-> ";
	cin >> deCaeChoice;
	if(!cin) {					// if input does not match data type
		cin.clear(); 			// clears error flags
 		cin.ignore(999,'\n'); 	// ignore input buffer to newline
	}
	switch(deCaeChoice)	{
		case 1: {
			cout << "\nEnter Clear Text" << endl; // prompt user for ciphertext
			cin.ignore();						  // clear input buffer
			getline(cin, cleartext);			  // save ciphertext
			// return decrypted transposition ciphertext
			cout << "Decrypted message: " << Menu::caesarDecrypt(cleartext) << endl;
			cout << endl;
			Menu::superMenu();				// call main submenu
			break;
		}
		case 2:
			Menu::decryptMenu();			// return to decyrption menu
			break;
		default:							// handle input out of range
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Again" << endl;
			Menu::sleep();					// delay return to top for error message
			Menu::deCaeMenu();				// return to top of function
			break;
	}
}
// Brute-force submenu
void Menu::bfMenu()
{
	Menu::clear_screen();					// clear screen
	cout << endl;
	cout << "*************************************" << endl;
	cout << "*            Decryption             *" << endl;
	cout << "*                                   *" << endl;
	cout << "*          Unknown Cipher           *" << endl;
	cout << "* Please select from the menu below *" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Attempt to decrypt using a bruteforce method" << endl;
	cout << "2) Return to the decryption Menu" << endl;
	cout << "-> ";
	cin >> bfChoice;
	if(!cin) {					// if input does not match data type
		cin.clear(); 			// clears error flags
 		cin.ignore(999,'\n'); 	// ignore input buffer to newline
	}
	switch(bfChoice)	{
		// choice 1
		case 1: {
			cout << "\nEnter Clear Text" << endl;	// prompt user for unknown cipher text
			cin.ignore();							// clear input buffer
			getline(cin, cleartext);		// save ciphertext
			Menu::bruteforce(cleartext);	// return transposition array / sub decrypt attempt
			cout << endl;
			Menu::superMenu();			// return to main submenu
			break;
		}
		// choice 2
		case 2:
			Menu::decryptMenu(); 		// return to decryption menu
			break;
		default:						// handle input out of range
			cout << endl;
			cout << "Invalid Choice" <<
					"\nPlease Choose Agagin" << endl;
			Menu::sleep();			// delay for error message
			Menu::bfMenu();			// return to top of function
			break;
	}
}
// Program main submenu
void Menu::superMenu()
{
	cout << endl;
	cout << "***************************" << endl;
	cout << "*   Please choose where   *" << endl;
	cout << "* you'd like to return to *" << endl;
	cout << "*   from the menu below   *" << endl;
	cout << "***************************" << endl;
	cout << endl;

	// prompt user for menu selection
	cout << "1) Encryption Menu" << endl;
	cout << "2) Decryption Menu" << endl;
	cout << "3) Main Menu" << endl;
	cout << "-> ";
	cin >> superChoice;
	if(!cin) {						// if input does not match data type
		cin.clear(); 				// clears error flags
 		cin.ignore(999,'\n'); 		// ignore input buffer to newline
	}
	switch (superChoice) {
	// choice 1
	case 1:
		Menu::encryptMenu();		// return to encryption menu
		break;
	// choice 2	
	case 2:
		Menu::decryptMenu();		// return to decryption menu
		break;
	// choice 3
	case 3:
		Menu::mainMenu();			// return to program main menu
		break;
	default:						// handling input out of range
		cout << endl;
		cout << "Invalid Choice" <<
				"\nPlease Choose Again" << endl;
		Menu::sleep();				// delay for error message
		Menu::superMenu();			// return to top of menu
		break;
	}
}

// clear screen function
void Menu::clear_screen() {
	#ifdef WINDOWS					// if architecture matches windows
	    std::system("cls");			// return system 'cls'
	#elif _WIN32					// if 32-bit win architecture
		std::system("cls");			// return system 'cls'
	#elif _WIN64					// if 64-bit win architecture
		std::system("cls");			// return system 'cls'
	#else							// assume POSIX
	    std::system("clear");		// return system 'clear'
	#endif
}

// menu sleep (delay) function
void Menu::sleep() {
    using namespace std::this_thread;     	// sleep_for, sleep_until
    using namespace std::chrono_literals; 	// ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    sleep_for(1s);							// call sleep for 1 second
}

// end implementation file
