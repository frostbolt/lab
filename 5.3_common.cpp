#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h> 
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <cstring>
bool Alphabet(char s) { 
bool engl = ((int)s > 64 && (int)s < 91) || ((int)s>96 && (int)s < 123); 
bool rus = ((int)s > 191 && (int)s < 256) || (256 + (int)s > 191 && (256 + (int)s < 256)); 
return (engl || rus); 
} 
using namespace std;
int Search(char *word, char *direct) {
ifstream file;
file.open(direct);
int count = 0;
char line[81];
int l_word = strlen(word);
while (file.getline(line, 81)) {
char *p = line;
while (strstr(p, word)) {
p = strstr(p, word);
if (p != line)
if (Alphabet(*(p - 1))) {
p += l_word;
continue;
}
p += l_word;
if (!Alphabet(*p) || ((*p == '\0'))) count++;
}
}
file.close();
return count;
}
int main() {
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout<<"Лабораторная работа №5 задание №3"<<endl;
cout << endl;
cout << endl << "Поиск кол-ва слов в файле\n";
const int n3 = 81;
char word[n3];
for (int i = 0; i < 5; i++) {
cout << "Искать: ";
cin >> word;
cout << "Слово: " << word << " встретилось " << Search(word, "test.txt") << " раз(а).\n";
}
_getch();
return 0;
}