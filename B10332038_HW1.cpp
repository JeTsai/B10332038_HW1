#include<iostream>
#include<vector>
#include<string>

using namespace std;

string CaesarCipher(string text);
string MonoalphabeticCipher(string text);
string PlayfairCipher(string text);

int main() {

	string plainText = "sentfrommyiphone";
	cout << "Caesar cipher: " << CaesarCipher(plainText) << endl;
	cout << "Monoalphabetic cipher: " << MonoalphabeticCipher(plainText) << endl;

	cout << plainText;
	system("PAUSE");
}

string CaesarCipher(string text) {
	
	for (int i = 0; i < text.size(); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] += 3;
			if (text[i] > 'z') {
				text[i] -= 26;
			}
		}
		else if(text[i]>='A' && text[i]<='Z'){
			text[i] += 3;
			if (text[i] > 'Z') {
				text[i] -= 26;
			}
		}
	}

	return text;
}

string MonoalphabeticCipher(string text) {
	string key1 = "abcdefghijklmnopqrstuvwxyz";
	string key2 = "QWERTYUIOPASDFGHJKLZXCVBNM";
	int pos;

	for (int i = 0; i < text.size(); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] = key2[text[i] - 'a'];
		}
		else {
			pos = key2.find(text[i]);
			text[i] = key1[pos];
		}
	}
	return text;
}

string PlayfairCipher(string text) {
	char table[5][5] = { {'d','p','a','b','c'},
						 {'e','f','g','h','i'},
						 {'k','l','m','n','o'},
						 {'q','r','s','t','u'},
						 {'v','w','x','y','z'} };
	string key = "dpabcefghiklmnoqrstuvwxyz";
	string output = "";

	for (int i = 0; i < text.size()-1; i++) {
		output += text[i];
		if (text[i] == text[i+1]) {
			output += 'x';
		}
	}
	if (output.size() % 2 == 1) {
		output += 'x';
	}


}

