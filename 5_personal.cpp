#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h> 
#include <cstdlib>
#include <windows.h>
#include <cstdio>

using namespace std;

struct Triangle {
	float a;
	float b;
	// Triangle(float A, float B);
	// void Display();
};

// Triangle::Triangle(float A, float B) {
// 	a = A;
// 	b = B;
// }

// Triangle::Display() {
// 	cout << "a: " << a << "b: " << b << endl;
// }


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout.setf(std::ios::boolalpha); // Вывод true/false 

	//
	Triangle first;

	_getch();
	return 0;
}
