#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h> 
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

void first(char a[256]) {
	int i = 0;
	bool flag = true;

	while (a[i]!='\0') {
		if (flag) {
			cout << a[i];
			if (a[i] == ' ') {
				flag = false;
				cout << a[i+1] << " ";
			}
		} else {
			if (a[i] == ' ') {
				cout << a[i+1];
			}
		}
		i++;
	}
}

bool second(char string[256]) {
	int j = 0;
	char str[256];
	cout << str << endl;
	for (int i = 0; i < strlen(string); ++i) {
		if (string[i] == ' ') continue;
		str[j] = tolower(string[i]);
		j++;
	}
	str[j] = '\0';
	cout << str << endl;
	for (int i = 0; i < strlen(str)/2; ++i)	{
		if (str[i] != str[strlen(str) -1- i])	{
			return false;
		}
	}
	return true;
}

void third(char path[256]char path[80]) {
	ifstream file(path);
	char buffer[80];
	while (file.getline(buffer, 80)) {
		strstr(buffer, lf)
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout.setf(std::ios::boolalpha); // Вывод true/false 

	//
	char fio[256];
	cout << "ФИО: ";
	cin.getline(fio, 256);
	first(fio);


	//
	char s[256];
	cout << endl << "Строка: ";
	cin.getline(s, 256);
	cout << " Палиндром? - " << second(s) << endl;


	//
	char path[256] = "text.txt";
	char word[80];
	cin >> word;
	third(path, word);




	_getch();
	return 0;
}
