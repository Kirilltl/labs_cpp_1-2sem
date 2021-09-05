#include"point.h"
Point::Point(int x1, int y1, int z1)
{
	x = x1;
	y = y1;
	z = z1;
}
Point& Point::operator=(const Point& b)
{
	if (this != &b)
	{
		x = b.x;
		y = b.y;
		z = b.z;
	}
	return (*this);
}
Point Point::operator+(const Point& b)
{
	Point a = *this;
	a.x = x + b.x;
	a.y = y + b.y;
	a.z = z + b.z;
	return a;
}
ostream& operator<<(ostream& ost, const Point& b)
{
	ost<<"x = "<<b.x<<"y = "<<b.y<<"z = "<<b.z<<endl;
	return ost;
}