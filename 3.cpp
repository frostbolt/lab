
#include <iostream>
#include <ctime>
#include <time.h>


using namespace std;

template <typename T>
void print_r(T *a, int n) {
	for (int i=0; i<n; i++){
		cout << "array["<<i<< "] : "<< a[i] << "   " << endl;
	}
	cout << endl;
}

template <typename T>
void sel_sort(T *a, int n) {
	T cup;
	for(int i = 0; i < n -1; i++) {
		int min_index = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			cup = a[i];
			a[i] = a[min_index];
			a[min_index] = cup;
		}	
	}
}

template <typename T>
int binary_search(T *a, T ch, int n){ 
	if (a[0] == ch) {
		return 0;
	}
	int l = 0; 
	int r = n + 1; 
	int mid;
	while (l < r - 1) { 
		mid = (l + r) / 2; 
		if (a[mid]<ch) { 
			l = mid; 
		} 
		else { 
			r = mid; 
		} 
	} 
	if ( fabs(a[r]- ch) < 0.0001){ 
		return r; 
	}else{ 
		return -1;
	} 
} 


void quicksort(int a, int b, int *arr){ 
	int center = arr[(a + b) / 2]; 
	int na = a; int nb = b; 
	while (na <= nb) { 
		while (arr[na] < center) na++; 
		while (arr[nb] > center) nb--; 
		if (na <= nb) { 
			int cup; 
			cup=arr[na]; 
			arr[na]=arr[nb]; 
			arr[nb]=cup; 
			na++; 
			nb--; 
		} 
	} 
	if (na<b) quicksort(na, b, arr); 
	if (a<nb) quicksort(a, nb, arr); 
} 


void first(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = srand(time(0));
	}
}

void second(float *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = (float)srand(time(0))/100;
	}
}

int third(float *a, int n, float y) {
	int answer = -1;
	for (int i = 0; i < n; i++)	{
		if ( fabs((a[i] - y)) < 0.0001 ) {
			answer = i;
		}
	}
	return answer;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "int arr.      n: =";
	cin >> n;
	int *a = new int[n];

	srand(time(0));

	first(a, n);
	print_r(a,n);
	cout << endl;

	cout << "float arr.  n: =";
	cin >> n;
	float *b = new float[n];
	second(b, n);
	print_r(b,n);

	
	float y;
	cout << "y: =";
	cin >> y;
	int index = third(b, n, y);
	cout << "index: ";	if (index!=-1){	cout<< index; } else { cout << " -- ";}
	cout << endl;

	sel_sort(b, n);
	print_r(b, n);



	cout << "y = "; cin>>y; 
	index = binary_search(b, y, n);
	cout << "index: ";	if (index!=-1){	cout<< index; } else { cout << " -- ";}
	cout << endl;

	quicksort(0, n-1, a);
	print_r(a,n);

	delete[] a;
	delete[] b;
	_getch();
	return 0;
}
