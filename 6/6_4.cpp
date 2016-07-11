#include <iostream>
#include <sstream>
#include <conio.h>
#include <string.h>

//FRACTION

using namespace std;

class Pair {
public:
	virtual void add(Pair& p) = 0;
	virtual void sub(Pair& p) = 0;
	virtual void mul(Pair& p) = 0;
	virtual void div(Pair& p) = 0;
	virtual void print() = 0;
};

class FazzyNumber : public Pair
{
private:
	double x1,x,x2;
public:
	FazzyNumber(){};
	FazzyNumber(double t, double y, double z){ x1 = t; x = y; x2 = z; }
	void add(Pair& p){
		FazzyNumber temp = (FazzyNumber&)p;
		x1 = x1 + temp.x1;
		x = x + temp.x;
		x2 = x2 + temp.x2;
	}
	void sub(Pair& p){
		FazzyNumber temp = (FazzyNumber&)p;
		x1 = x1 - temp.x - (temp.x-temp.x1);
		x = x - temp.x;
		x2 = x2 - temp.x + (temp.x2 - temp.x);
	}
	void mul(Pair& p){
		FazzyNumber temp = (FazzyNumber&)p;
		x1 = x*temp.x - temp.x*(x - x1) - x*(temp.x - temp.x1) + (x - x1)*(temp.x - temp.x1);
		x = x * temp.x;												
		x2 = x*temp.x + temp.x*(x - x1) + x*(temp.x - temp.x1) + (x - x1)*(temp.x - temp.x1);
	}
	void div(Pair& p){
		FazzyNumber temp = (FazzyNumber&)p;
		x1 = x1/temp.x2;
		x = x / temp.x;
		x2 = x2/temp.x1;
	}

	void print(){
		cout << x1 << "," << x << ","<<x2<<endl;
	}
	
};

class Fraction : public Pair
{
private:
	long a; unsigned short b;
public:
	Fraction(){};
	Fraction(long A, unsigned short B){ a=A; b=B; }


	void add(Pair& p){
		Fraction temp = (Fraction&)p;
		
		if (a<0)
		{
			if (temp.a<0) {
				b+=temp.b;
			} else {
				b-=temp.b;
			}
		} else {
			if (temp.a<0) {
				b-=temp.b;
			} else {
				b+=temp.b;
			}
		}

	}
	void sub(Pair& p){
		Fraction temp = (Fraction&)p;
		a-=temp.a;
		if (a<0)
		{
			if (temp.a<0) {
				b-=temp.b;
			} else {
				b+=temp.b;
			}
		} else {
			if (temp.a<0) {
				b+=temp.b;
			} else {
				b-=temp.b;
			}
		}
	}
	void mul(Pair& p){

	}
	void div(Pair& p){

	}

	void print(){
		cout << a << "." << b <<endl;
	}
	
};

int main() {
	Pair*y = new FazzyNumber(1, 2, 3);
	Pair*z = new FazzyNumber(2, 4, 7);
	y->add(*z);
	y->print();
	y->mul(*z);
	y->print();
	// _getch();
	return 0;
}