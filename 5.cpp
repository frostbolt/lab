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
	char answer[256];
	int j = 0;
	while (a[i]!='\0') {
		if (flag) {
			answer[j] = a[i];			
			j++;
			if (a[i] == ' ') {
				answer[j+1] = a[i+1];			
				j++;
				flag = false;
			}
		} else {
			if (a[i] == ' ') {
				answer[j] = a[i];
				answer[j+1] = a[i+1];
				answer[j+2] = '\0';
			}
		}
		i++;
	}
	cout << answer;
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

void third(char path[256], char word[80]) {
	ifstream file(path);
	int counter =0;
	char buffer[80];
	while (file.getline(buffer, 80)) {
		while(strstr(buffer, word)) {
			counter++;
			
		}	
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout.setf(std::ios::boolalpha); 

	//
	char fio[256];
	cout << "���: ";
	cin.getline(fio, 256);
	first(fio);


	//
	char s[256];
	cout << endl << "������: ";
	cin.getline(s, 256);
	cout << " ���������? - " << second(s) << endl;


	//
	char path[256] = "text.txt";
	char word[80];
	cin >> word;
	third(path, word);




	_getch();
	return 0;
}
