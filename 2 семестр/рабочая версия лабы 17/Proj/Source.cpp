//#include<iostream>
//using namespace std;
//template<typename T>
//class Car{
//
//public:
//	
//	void drive()
//	{
//		cout << "we drive int " << endl;
//	}
//
//	void stop()
//	{
//		cout << "we stop " << endl;
//	}
//	
//};
//template<>
//class Car<char*> {
//
//public:
//
//	
//
//	void drive()
//	{
//		cout << "we drive char* " << endl;
//	}
//
//	void stop()
//	{
//		cout << "we stop " << endl;
//	}
//
//};



//class Point {
//private:
//	int x, y, z;
//public:
//	Point(int x1, int y1, int z1)
//	{
//		x = x1;
//		y = y1;
//		z = z1;
//	}
//	Point() { x = y = z = 0; };
//};
//int main() {
//	
//	Car<int> a;
//	a.drive();
//	a.stop();
//
//	Car<char*> b;
//	b.drive();
//	b.stop();
//
//	
//}
#include "header.h"
//#include "point.h"
#include<iostream>
#include<stdexcept>
using namespace std;
int main() {
	try
	{
		Set<char*> s;
		s.insert("a");
		s.insert("b");

		s.insert("c");
		cout << "	the content of the first set:" << endl;
		s.print_all();
		//if (s.find("ccc") == 1)
		//	cout << "ccc is in this set" << endl;
		//if (s.find("ddd") == 0)
		//	cout << "ddd is not in this set" << endl;
		Set<char*> s2;
		s2.insert("a");
		s2.insert("b");
		s2.insert("g");
		cout << "	the content of the second set:" << endl;
		s2.print_all();
		Set<char*> n;
		s.intersect(s2, n);
		cout << "intersect:" << endl;
		n.print_all();
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
	}
}
