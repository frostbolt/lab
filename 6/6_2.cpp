//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <conio.h>
#include <string.h>
#include <ctime>

using namespace std;


struct Subject {
	string name;
	unsigned char semester;
	unsigned char lectures;

};


class WorkTeacher {
	string last_name;
	time_t time;


	WorkTeacher(WorkTeacher &original) {}

	WorkTeacher() {}

	WorkTeacher() {}

	~WorkTeacher(){}

	string toString() {
		ostringstream result;
		result << "" << endl;
		return result.str();
	}
	friend ostream& operator << (std::ostream &out, WorkTeacher &t);
	friend istream& operator >> (istream &out, WorkTeacher &t);

};

ostream& operator << (ostream &out, WorkTeacher &t){
	return (out << t.toString());
}

istream& operator >> (istream &in, WorkTeacher &t){
	cout << "header ";
	in >> t.header;
	cout << "pos.x ";
	in >> t.pos.x;
	cout << "pos.y ";
	in >> t.pos.y;
	cout << "size.height ";
	in >> t.size.height;
	cout << "size.width ";
	in >> t.size.width;
	cout << "color ";
	in >> t.color;
	cout << "visability ";
	in >> t.visability;
	cout << "bordered ";
	in >> t.bordered;
	return in;
}


int main()
{
	_getch();
	return 0;
}