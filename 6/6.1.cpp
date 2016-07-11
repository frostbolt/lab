
// 18 вариант. Задание №23

//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <conio.h>
#include <string.h>

#define DISPLAY_W 1366
#define DISPLAY_H 768

using namespace std;

bool checkWindow(int x, int y, int sw, int sh) {
	if (((x + sw) <= DISPLAY_W) && ((y + sh) <= DISPLAY_H) && (x >= 0) && (y >= 0)) {
		return true;
	}
	return false;
}

struct coord {
	int x, y;
	bool operator == (coord &original) {
		if (x == original.x && y == original.y) {
			return true;
		}
		return false;
	}
};

struct dimensions {
	int width, height;
	bool operator == (dimensions &original) {
		if (width == original.width && height == original.height) {
			return true;
		}
		return false;
	}
};

class ModelWindow {

	string header;
	coord pos;
	dimensions size;
	unsigned long long color;
	bool visability, bordered;

	public:

	bool operator == (ModelWindow &original) {
		if (this->header == original.header && this->pos == original.pos && this->size == original.size &&
			this->color == original.color && this->visability == original.visability && this->bordered == original.bordered) {
			return true;
		}
		return false;
	}

	bool moveWindowV(int dY) {
		if (checkWindow(pos.x, pos.y + dY, size.width, size.height)){
			pos.y += dY;
			return true;
		}
		return false;
	}

	bool moveWindowH(int dX) {
		if (checkWindow(pos.x + dX, pos.y, size.width, size.height)){
			pos.x += dX;
			return true;
		}
		return false;
	}

	bool resize(int dH = 0, int dW = 0) {
		if (checkWindow(pos.x, pos.y, size.width + dW, size.height + dH)){
			size.height += dH;
			size.width += dW;
			return true;
		}
		return false;
	}

	ModelWindow(ModelWindow &original) {
		this->header = original.header;
		this->pos = original.pos;
		this->size = original.size;
		this->color = original.color;
		this->visability = original.visability;
		this->bordered = original.bordered;
	}

	ModelWindow(int x, int y, int w, int h, string hdr, unsigned long long clr, bool visab, bool brdrd) {
		header = hdr;
		pos.x = x;
		pos.y = y;
		size.height = h;
		size.width = w;
		color = clr;
		visability = visab;
		bordered = brdrd;
	}

	ModelWindow() {
		header = "new window";
		pos.x = 80;
		pos.y = 20;
		size.height = 800;
		size.width = 600;
		color = 0xFFFFFF;
		visability = true;
		bordered = true;
	}

	~ModelWindow(){}

	string toString() {
		ostringstream result;
		result << "(window) { " << '\n' << '\t' << "'header' => '" << header << "'," << '\n' << '\t' << "'pos.x' => " << pos.x << "," << '\n' << '\t' << "'pos.y' => " << pos.y << "," << '\n' << '\t' << "'size.height' => " << size.height;
		result << "," << '\n' << '\t' << "'size.width' => " << size.width << "," << '\n' << '\t' << "'color' => " << color << "," << '\n' << '\t' << "'visability' => " << visability << "," << '\n' << '\t' << "'bordered' => " << bordered;
		result << '\n' << "}" << endl;
		return result.str();
	}
	friend ostream& operator <<(std::ostream &out, ModelWindow &t);
	friend istream& operator >> (istream &out, ModelWindow &t);


};

ostream& operator << (ostream &out, ModelWindow &t){
	return (out << t.toString());
}

istream& operator >> (istream &in, ModelWindow &t){
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


int main() {
	ModelWindow a, b(0, 0, 100, 50, "hedr", 0x000000, true, true);
	cout << a;
	cout << b;
	cout << (a == b) << endl;
	a = b;
	cout << a;
	cout << (a == b) << endl;
	_getch();
	return 0;
}