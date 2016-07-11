
// 18 вариант.


// умн?

//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <conio.h>
#include <string.h>

using namespace std;

class Pair {
protected:
	float a, b;
public:
	Pair(float A, float B) {
		a=A;
		b=B;
	}

	Pair(const Pair &p) {
		a=p.a;
		b=p.b;
	}

	void setA(float A) {
		a=A;
	}

	void setB(float B) {
		b=B;
	}

	float getA() {
		return a;
	}

	float getB() {
		return b;
	}

	void add(Pair p) {
		a+=p.a;
		b+=p.b;
	}

	void sub(Pair p) {
		a-=p.a;
		b-=p.b;
	}

	void mul(Pair p) {
		a*=p.a;
		b*=p.b;
	}
	void print(){
		cout << "("<< a <<","<< b << ")" << endl;
	}
	friend Pair& operator + (Pair &first, Pair &second);

};

Pair& operator + (Pair &first, Pair &second){
	static Pair temp(first);
	temp.add(second);
	return temp;
}

class Complex :public Pair {
public:
	Complex(float A, float B) :Pair(A,B){}

	Complex(const Complex &p) :Pair(p.a,p.b){}
	void mul(Complex p){
		a=a*p.a-b*p.b;
		b=a*p.b + b*p.a;
	}
	friend Complex& operator + (Complex &first, Complex &second);
	friend Complex& operator * (Complex &first, Complex &second);
	friend Complex& operator - (Complex &first, Complex &second);
};

Complex& operator + (Complex &first, Complex &second){
	static Complex temp(first);
	temp.add(second);
	return temp;
}
Complex& operator * (Complex &first, Complex &second){
	static Complex temp(first);
	temp.mul(second);
	return temp;
}
Complex& operator - (Complex &first, Complex &second){
	static Complex temp(first);
	temp.sub(second);
	return temp;
}

int main() {
	Complex a(10,0);
	Complex b(2,2);
	Complex c(0,0);
	c = a*b;
	c.print();
	// _getch();
	return 0;
}