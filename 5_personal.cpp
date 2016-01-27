#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h> 
#include <cstdlib>
#include <windows.h>
#include <cstdio>

using namespace std;

// struct Triangle {
// 	float a;
// 	float b;
// 	// Triangle(float A, float B);
// 	// void Display();
// };

// // Triangle::Triangle(float A, float B) {
// // 	a = A;
// // 	b = B;
// // }

// // Triangle::Display() {
// // 	cout << "a: " << a << "b: " << b << endl;
// // }


// int main() {
// 	SetConsoleCP(1251);
// 	SetConsoleOutputCP(1251);
// 	std::cout.setf(std::ios::boolalpha); // Âûâîä true/false 

// 	//
// 	Triangle first;

// 	_getch();
// 	return 0;
// }


struct triangle
{
	float a;
	float b;
	void Read() {
		cout << "Сторона а= ";
		cin >> a;
		cout << "Сторона b= ";
		cin >> b;
	}

	bool Init() {
		return (a > 0) && (b > 0);
	}

	void Display() {
		if (Init()) {
		}
		else cout << "Данные некорректны" << endl;
	}
};


float Striangle(triangle q) {
	return q.a*q.b / 2;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout<<"Лабораторная работа №5 Индивидуальное задание №2"<<endl;
	cout << endl;
	cout << endl << "Вычисление площади треугольника" << endl;
	cout << endl;

	triangle t;
	t.Read();
	t.Display();
	cout << "Площадь треугольника: " << Striangle(t) << endl;
	_getch();
	return 0;
}