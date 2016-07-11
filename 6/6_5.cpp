#include <iostream>
#include <sstream>
#include <conio.h>
#include <string.h>
#include <math.h>

using namespace std;

class Point {
private:
	float x,y;
public:
	Point(float X,float Y){
		x=X;
		y=Y;
	};

	bool eq(Point b) {
		return ((x==b.x)&&(y==b.y));
	}

	float distance(Point b){
		try{
			if (this->eq(b)) throw true;
			return sqrt(pow((x-b.x),2)+pow((y-b.y),2));
		}
		catch (bool a){
			cout << "exeption" <<endl;
			return 0;
		}
	}
};

int main() {
	Point a(1,3);
	Point b(2,2);

	cout << a.distance(b)<< endl;
	cout << a.distance(a) << endl;

	_getch();
	return 0;
}