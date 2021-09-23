#include "Header_t.h"
#include "Header.h"
#include "point.h"
#include<iostream>
#include<stdexcept>
using namespace std;
int main() {
	try
	{
		{
			Set<int> s;
			s.insert(1);
			s.insert(6);
			s.insert(7);
			cout << "	The content of the first set:" << endl;
			s.print_all();
			Set<int> s2;
			s2.insert(1);
			s2.insert(2);
			s2.insert(4);
			cout << "	The content of the second set:" << endl;
			s2.print_all();
			Set<int> n;
			s.intersect(s2, n);
			cout << "	Intersect:" << endl;
			n.print_all();
		}
		{
			Set<char*> s;
			s.insert("a");
			s.insert("h");
			s.insert("k");
			cout << "	The content of the first set:" << endl;
			s.print_all();
			if (s.find("h") == 1)
				cout << "h is in this set" << endl;
			if (s.find("l") == 0)
				cout << "l is not in this set" << endl;
			Set<char*> s2;
			s2.insert("a");
			s2.insert("b");
			s2.insert("g");
			cout << "	The content of the second set:" << endl;
			s2.print_all();
			Set<char*> n;
			s.intersect(s2, n);
			cout << "	Intersect:" << endl;
			n.print_all();
		}
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
	}
}
