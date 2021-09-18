#include"func.h"
#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
	try {
		int n, r;
		cout << "Input 1 row count" << endl;
		cin >> n;
		cout << "Input 1 column count" << endl;
		cin >> r;
		Matrix<int> m1(n,r);
		m1.set();
		int v, q;
		cout << "Input 2 row count" << endl;
		cin >> v;
		cout << "Input 2 column count" << endl;
		cin >> q;
		Matrix<int> m2(v,q);
		m2.set();
		int s = n = v;
		int c = r = q;
		Matrix<int> m3(s,c);
		m3 = m1.sum(m2);
		m3.print();
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}