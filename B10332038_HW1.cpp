#include<iostream>
#include<string>

using namespace std;

string CaesarCipher(string text);
string MonoalphabeticCipher(string text);
string PlayfairCipher(string text);
string VenamCipher(string text);
string RowTransposition(string text);
string ProductCipher(string text);

int main() {

	string plainText = "sentfrommyiphone";
	cout << "Plain text: " << plainText << endl;
	cout << "Caesar cipher: " << CaesarCipher(plainText) << endl;
	cout << "Monoalphabetic cipher: " << MonoalphabeticCipher(plainText) << endl;
	cout << "Playfair Cipher: " << PlayfairCipher(plainText) << endl;
	cout << "Venam cipher: " << VenamCipher(plainText) << endl;
	cout << "Row transposition cipher: " << RowTransposition(plainText) << endl;
	cout << "Product cipher: " << ProductCipher(plainText) << endl;

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

	output += text[0];
	for (int i = 1; i < text.size(); i++) {
		if (text[i-1] == text[i]) {
			output += 'x';
		}
		output += text[i];
	}
	if (output.size() % 2 == 1) {
		output += 'x';
	}
	
	char a, b;
	int pos1_x,pos1_y,pos2_x, pos2_y;

	for (int i = 0; i < output.size(); i += 2) {
		a = output[i];
		b = output[i + 1];
		pos1_x = key.find(a)/5;
		pos1_y = key.find(a)%5;
		pos2_x = key.find(b) / 5;
		pos2_y = key.find(b) % 5;

		if (pos1_x == pos2_x) {
			pos1_y++;
			pos2_y++;
			if (pos1_y > 4) pos1_y -= 5;
			if (pos2_y > 4) pos2_y -= 5;
			output[i] = table[pos1_x][pos1_y];
			output[i+1] = table[pos2_x][pos2_y];
		}
		else if (pos1_y == pos2_y) {
			pos1_x++;
			pos2_x++;
			if (pos1_x > 4) pos1_x -= 5;
			if (pos2_x > 4) pos2_x -= 5;
			output[i] = table[pos1_x][pos1_y];
			output[i+1] = table[pos2_x][pos2_y];
		}
		else {
			output[i] = table[pos1_x][pos2_y];
			output[i+1] = table[pos2_x][pos1_y];
		}
	}
	return output;
}

string VenamCipher(string text) {
	string key = "kmt";
	int k = 0;
	int temp1,temp2;
	for (int i = 0; i < text.size(); i++) {
		temp1 = text[i] - 'a' ;
		temp2 = key[k] - 'a' ;
		temp1 = temp1 ^ temp2;
		temp1 = temp1 % 26;
		text[i] = temp1 + 'a';
		k++;
		if (k > 2) k = 0;
	}
	return text;
}

string RowTransposition(string text) {
	int column[8] = { 5,2,8,3,4,6,7,1 };
	string output = "";
	char plaintext[2][8];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			plaintext[i][j] = text[i * 8 + j];
		}
	}
	int pos;
	for (int i = 1; i <= 8; i++) {
		for (pos = 0; pos < 8;pos++){
			if (column[pos] == i) break;
		}
		output += plaintext[0][pos];
		output += plaintext[1][pos];
	}
	return output;
}

string ProductCipher(string text) {
	int transport[16] = { 15,11,2,10,16,3,7,14,4,12,9,6,1,5,8,13 };
	string output="";
	int pos;
	for (int i = 0; i < text.size(); i++) {
		pos = transport[i] - 1;
		output += text[pos];
	}


	return output;
}