// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

// #include "stdafx.h"
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

void fill_in_rand_int(int **a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() / 2000 - RAND_MAX / 4000;
		}
	}
}

void fill_in_rand_float(float **a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)	{
			a[i][j] = rand() / 2000 - RAND_MAX / 4000;
		}
	}
}

template <typename T>
void print_r(T **a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

// template <typename T>
// void multiply(T **a, int dim1, int dim2, T **b, int dim3, int dim4, T **c) {
// 	if (dim2 == dim3) {
// 		for (int i = 0; i < dim1; i++) {
// 			for (int j = 0; j < dim4; j++) {
// 				c[i][j] = 0;
// 				for (int k = 0; k < dim2; k++) {
// 					c[i][j] += a[i][k] * b[k][j];
// 				}
// 				cout << c[i][j] << "\t";
// 			}
// 			cout << endl;
// 		}
// 		return;
// 	}
// 	cout << "Эти матрицы нельзя умножить.";
// 	return;
// }

// template <typename T>
// float first_personal(T **a, int dim1, int dim2) {
// 	float max_subzero = -RAND_MAX;
// 	bool flag = true;
// 	float sum = 0;
// 	for (int i = 0; i < dim1; i++) {
// 		for (int j = 0; j < dim2; j++) {
// 			if ((a[i][j] > max_subzero) && (a[i][j] < 0)) {
// 				if (flag) {
// 					max_subzero = a[i][j];
// 					flag = false;
// 				}
// 				else {
// 					sum += max_subzero;
// 					max_subzero = a[i][j];
// 				}
// 			}
// 		}
// 	}
// 	return sum;
// }

// template <typename T>
// void translation(T **a, int dim1, int dim2, int steps = 1) {
// 	for (int step = 0; step < steps; step++) {
// 		T *last = new T[dim1];
// 		for (int i = 0; i < dim1; i++) {
// 			last[i] = a[i][dim2 - 1];
// 		}
// 		for (int i = (dim1 - 1); i >= 0; i--) {
// 			for (int j = (dim2 - 1); j > 0; j--) {
// 				a[i][j] = a[i][j - 1];
// 			}
// 		}
// 		for (int i = 0; i < dim1; i++) {
// 			a[i][0] = last[i];
// 		}


// 	}
// }


// template <typename T>
// void sort(T **a, int dim1, int dim2) {

// 		T *index = new T[dim1];
// 		for (int i = 0; i < dim1; i++) {
// 			for (int j = 0; j < dim2; j += 2) {
// 				index[i] *= a[i][j];
// 			}
// 		}

// 		for (int i = 0; i < dim1; i++) {

// 		}

// }

int main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));

	int dim1, dim2, dim3, dim4;
	cout << "Размерность 1:" << endl;
	cin >> dim1 >> dim2;

	// cout << "Размерность 2:" << endl;
	// cin >> dim3 >> dim4;
	cout << endl;	cout << endl;	cout << endl;	cout << endl;
	int **a = new int *[dim1];
	for (int i = 0; i < dim1; i++) {
		a[i] = new int[dim2];
	}

	// int **b = new int *[dim3];
	// for (int i = 0; i < dim3; i++) {
	// 	b[i] = new int[dim4];
	// }

	// int **c = new int *[dim1];
	// for (int i = 0; i < dim1; i++) {
	// 	c[i] = new int[dim3];
	// }

	fill_in_rand_int(a, dim1, dim2);
	print_r(a, dim1, dim2);

	cout << endl;	cout << endl;

	// fill_in_rand_int(b, dim3, dim4);
	// print_r(b, dim3, dim4);

	// cout << endl;	cout << "Произведение этих матриц:"; cout << endl;

	// multiply(a, dim1, dim2, b, dim3, dim4, c);


	// cout << endl; cout << "Матрица 5*9:"; cout << endl;

	// float **d = new float *[5];
	// for (int i = 0; i < 5; i++) {
	// 	d[i] = new float[9];
	// }

	// fill_in_rand_float(d, 5, 9);
	// print_r(d, 5, 9);
	// cout << "Сумма элементов, меньших максимального отрицательного: " << first_personal(d, 5, 9) << endl;

	// cout << endl;	cout << endl;

	// cout << "Смещение 1 матрицы: " << endl;
	// print_r(a, dim1, dim2);
	// cout << endl;
	// translation(a, dim1, dim2);
	// print_r(a, dim1, dim2);
	// cout << endl;



	_getch();

	return 0;
}

