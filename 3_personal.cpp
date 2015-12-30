#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h> 
#include <cstdlib>

using namespace std;

template <typename T>
void print_r(T *a,int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

int fill_in_rand_int(int *a, const int n) {
	srand (time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10 - 5;
	}
	cout << endl;
}

float fill_in_rand_float(float *a, const int n) {
	srand (time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = (float)(rand() %10000)/1000-5;
	}
	cout << endl;
}

template <typename T>
T first_personal(T *a,int n) {
	T answer = abs(a[0]);
	for (int i = 2; i < n; i+=2) {
		answer*=abs(a[i]);
	}
	return answer;
}

template <typename T>
T second_personal(T *a,int n) {
	T answer = 0;
	bool flag1 =false, flag2 = false;
	n--;
	while(!flag1) {
		if(a[n]< 0) {
			if (!flag2)	{
				flag2 = true;
				answer+= a[n];
			} else {
				flag1 = true;
			}
		} else {
			answer+= a[n];
		}
		n--;
	}
	return answer;
}

template <typename T>
void third_personal(T *a,int n) {
	for (int i = 1; i < n; i++) {
		if (abs(a[i]) < 0.5) { // Чтобы срабатывало чаще. 
			a[i] = (T)1/i;
		}
	}
}

template <typename T>
void fourth_personal(T *a,int n) {
	T cup;
	for (int i = 0; i < n; i++) {
		if (a[i] < a[0]) {
			// Можно ли прикрутить сортировку?
		} 
	}
}

int main(){
	int n;
	cout << "size: ";
	cin >> n;
	int *a = new int[n];
	float *b = new float[n];
	fill_in_rand_int(a,n);
	fill_in_rand_float(b,n);
	print_r(a,n);
	print_r(b,n);

	// Вариант 20: произведение модулей элементов массива с четными номерами
	cout << first_personal(a,n) << endl;

	// Вариант 20: сумму элементов массива, расположенных правее предпоследнего отрицательного элемента.
	cout << second_personal(b,n) << endl;

	// Вариант 20: все нулевые элементы на величины, обратные их номерам
	// (если нулевой по номеру элемент окажется равен нулю, его не заменять).
	third_personal(b,n);
	print_r(b,n);

	// Вариант 20: Преобразовать массив таким образом, чтобы сначала располагались элементы,
	// отличающиеся от минимального не более чем на 15%, а потом все остальные
	fourth_personal(a,n);

	delete []a;
	_getch();
}