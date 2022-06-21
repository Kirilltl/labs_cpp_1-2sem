#ifndef POINT_H
#define POINT_H
#include <iostream>
class Point
{
private:
	int x, y, z;
public:
	Point(int a = 0, int b = 0, int c = 0) { 
		x = a;
		y = b;
		z = c; 
	}
	const Point& operator=(const Point& p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream &out, Point &p);
};
std::ostream& operator<<(std::ostream& out, Point& p) {
	out << " " << p.x << " " << p.y << " " << p.z << " ";
	return out;
	}
#endif