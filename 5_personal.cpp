#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct triangle {
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


struct Time {
	int h, m;
	void Display() {
		cout << h << "h " << m << "m." << endl;
	}
	void Read() {
		do {
			cout << "h: ";
			cin >> h;
			cout << "m: ";
			cin >> m;
		} while (!this->Init(h,m));
	}
	bool Init(int hours, int minutes) {
		if ((hours <= 23) && (minutes <= 59)) {
			return true;
		}
		return false;
	}
};

int to_minutes(Time a) {
	return (a.m + a.h*60);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time a;
	a.Read();
	a.Display();
	cout << "^ convert to minutes: " << to_minutes(a);

	_getch();
	return 0;
}