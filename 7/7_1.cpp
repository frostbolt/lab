#include <fstream>
#include <iostream>
#include "conio.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int rnd(){
	return ((rand() % 101)-50);
}

void write(ofstream &file){
	int ary[100];
	ary[0] = rnd();
	int min = ary[0];
	int max = ary[0];

	for (int i = 1; i<100; i++) {
		ary[i] = rnd();
		if (ary[i] < min) min = ary[i];
		if (ary[i] > max) max = ary[i];
	}
	max-=min;
	for (int i = 0; i < 100; i++) {
		if (i%2 == 0) {
			file << max << endl;
		} else {
			file << ary[i] << endl;
		}
	}
}

int main(){
	srand(time(0));
	ofstream file;
	file.open("7_1.txt");
	write(file);
	return 0;
}
