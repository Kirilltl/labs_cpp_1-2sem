#include <iostream>
using namespace std;
class Point
{
private:
	int x,y,z;
public:
	Point() {x=y=z=0;};//conctructor umolchanie
	Point(int x1, int y1, int z1);
	Point& operator=(const Point& b);
	Point operator+(const Point& b);
	friend ostream& operator<<(ostream& ost, const Point& b);
};

