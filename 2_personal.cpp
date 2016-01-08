#include <iostream>
#include <conio.h>
#include <cmath>
#include <stdio.h>

using namespace std;

void third(float x, float x2, float dx, float eps) {
	float const PI = 3.14159265;	
	cout << endl << " x \t\tf(x) \t\tu" << endl << endl;
	while (x <= x2+0.0001) {
		float sum = x;
		float current_unit = pow(x,3)/(6);
		float current_numerator = 3*pow(x,5);
		float current_denominator = 2*4*5;
		int n = 2;
		while (current_unit > eps) {
			sum += current_unit;
			current_unit = current_numerator / current_denominator;
			current_numerator*=pow(x,2)*(2*n-1);
			current_denominator*= (2*n+1);
			n++;
		}
		float fx = PI / 2 - sum;
		printf("%2.2f\t\t", x);
		printf("%f", fx);
		cout << "\t" << n << endl;
		x += dx;
	}
}

void fourth(int *max, int *max2) {
	int input;
	cin >> input;
	if (input !=0) {
		if (input > *max) {
			*max2 = *max;
			*max = input;
		} else if (input > *max2) {
			*max2 = input;
		}

		fourth(&(*max), &(*max2));
	}
}


int main() {

	// 3 индивид.

	float x = -0.9, x2 = 0.9, dx = 0.1, eps = 0.0001;
	//cin >> x;
	//cin >> x2;
	//cin >> dx;
	//cin >> eps;
	third(x, x2, dx, eps);

	// 4 индивид.

	int max = 0;
	int max2 = 0;

	fourth(&max, &max2);

	cout << endl << "2nd max: " << max2;

	_getch();

    return 0;
}