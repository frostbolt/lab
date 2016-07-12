// mingw ????

#include <iostream>
#include "conio.h"
#include <ctime>
#include <cstdlib>
#include <vector> 
#include <algorithm>  
#include <iterator>

using namespace std;
int rnd() {
	return ((rand() % 100) - 50);
}

void print_vector(vector<int> v) {
	cout << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "  "));
	cout << endl;
}

void task() {
	// заменить все четные числа на разность максимума и минимума
	vector<int> myvector(100);
	generate(myvector.begin(), myvector.end(), rnd); // случ числ.
	print_vector(myvector);
	int max = -51;
	int min = 51;
	for_each(myvector.begin(), myvector.end(), [&max](int x) {max = (max>x) ? max : x; });
	for_each(myvector.begin(), myvector.end(), [&min](int x) {min = (min<x) ? min : x; });
	max -= min;
	for_each(myvector.begin(), myvector.end(), [&max](int &x) {x = (x % 2 == 0) ? max : x; });

	print_vector(myvector);
}

int main() {
	srand(unsigned(time(0)));
	task();
	_getch();
}