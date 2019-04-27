#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string caesarEncrypt(string cleartext, int shift=1) {

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ciphertext;
    int caesarindex;

    for(int i{0};i<=cleartext.length();i++) {
        for(int j{0};j<26;j++) {
            if(cleartext[i] == ' ' ) {
                ciphertext += ' ';
                break;           
            }
            if(cleartext[i] == alpha[j]) {
                caesarindex = (j + shift) % 26;
                ciphertext += alpha[caesarindex];
                break;
            }
        }
    }
    return ciphertext;
}

string caesarDecrypt(string cleartext,int shift=1) {

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ciphertext;
    int caesarindex;

    for(int i{0};i<=cleartext.length();i++) {
        for(int j{0};j<26;j++) {
            if(cleartext[i] == ' ' ) {
                ciphertext += ' ';
                break;           
            }
            if(cleartext[i] == alpha[j]) {
                caesarindex = (j - shift) % 26;
                ciphertext += alpha[caesarindex];
                break;
            }
        }
    }
    return ciphertext;
}

string subEncrypt(string cleartext, int shift=0) {
    
    string alpha =    "kfleyinjxrawdchvumtqzpsgob";
    string subalpha = "moswlfxtecbjnypzkgqudhvria";
    string ciphertext;
    int subindex;

    for(int i{0};i<=cleartext.length();i++) {
        for(int j{0};j<26;j++) {
            if(cleartext[i] == ' ' ) {
                ciphertext += ' ';
                break;
            }
            if(cleartext[i] == alpha[j]) {
                subindex = (j + shift) % 26;
                ciphertext += subalpha[subindex];
                break;
            }
        }
    }
    return ciphertext;
}

string subDecrypt(string cleartext, int shift=0) {
    
    string alpha =    "kfleyinjxrawdchvumtqzpsgob";
    string subalpha = "moswlfxtecbjnypzkgqudhvria";
    string ciphertext;
    int subindex;

    for(int i{0};i<=cleartext.length();i++) {
        for(int j{0};j<26;j++) {
            if(cleartext[i] == ' ' ) {
                ciphertext += ' ';
                break;
            }
            if(cleartext[i] == subalpha[j]) {
                subindex = (j + shift) % 26;
                ciphertext += alpha[subindex];
                break;
            }
        }
    }
    return ciphertext;
}

void bruteforce(string ciphertext) {

    cout << left << setw(35) << "Caesar Brute Force" << "Substitution Brute Force"<< endl;
    for(int shift{1};shift<=26;shift++) {
        cout << left << setw(35) << caesarEncrypt(ciphertext,shift);
        cout << subDecrypt(ciphertext,shift) << endl;
    }
}

int main() {

    string cleartext,ciphertext;

    cout << "Enter Clear Text" << endl;
    getline(cin,cleartext);
    cout << endl;
    cout << "Caesar" << endl;
    cout << "Encrypt: " << caesarEncrypt(cleartext)<< endl;
    cout << "Decrypt: " << caesarDecrypt(caesarEncrypt(cleartext)) << endl;
    cout << endl;
    cout << "Substitution" << endl;
    cout << "Encrypt: " << subEncrypt(cleartext) << endl;
    cout << "Decrypt: " << subDecrypt(subEncrypt(cleartext)) << endl;
    cout << endl;
    cout << "Bruteforce" << endl;
    // cout << subEncrypt("triple zulu one two three") << endl;
    // cout << subDecrypt(subEncrypt(cleartext)) << endl;
    bruteforce(subEncrypt(cleartext));
    
}