#include <fstream>
#include <iostream>
#include "conio.h"
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

void repl(string &str, string &word1, string &word2) {
	while (str.find(word1) != -1) {
		int position = str.find(word1);
		str.replace(position, word1.length(), word2);
	}
}

void reading(ifstream &file){
	while (!file.eof()){
		string str;
		string word1;
		word1="if";
		string word2;
		word2="if(";
		getline(file, str);
		cout << str << "\t<-- source" << endl;
		repl(str,word1,word2);
		cout <<str<<"\t<-- edited" << endl;
	}
}

int main() {

	ifstream file("pas.pas");
	file.close();

	reading(file);

	_getch();
	return 0;
}