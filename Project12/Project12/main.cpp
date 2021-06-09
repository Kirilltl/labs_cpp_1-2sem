#include <iostream>
#include "String.h"
using namespace std;
#define MAX_LEN 100
int main()
{
	char* s = new char[MAX_LEN];
	cout << "Enter a string" << endl;
	cin >> s;
	cout << s << endl;
	MyString str(s);
	MyString child(str);
	MyString father = str;
	cout << "--- len ---" << endl;
	cout << child.len() << endl;
	cout << "--- del_substr ---" << endl;
	int x;
	int y;
	cout << "Input first index" << endl;
	cin >> x;
	cout << "Input last index" << endl;
	cin >> y;
	father.del_substr(x, y);
	father.print();
	cout << "--- ins ---" << endl;
	int r;
	cout << "Input index" << endl;
	cin >> r;
	char c;
	cout << "Input symbol" << endl;
	cin >> c;
	child.ins(r, c);
	child.print();
	cout << "--- concat ---" << endl;
	char* w = new char[MAX_LEN];
	cout << "Enter the string to add" << endl;
	cin >> w;
	MyString cot(w);
	MyString res = str + cot;
	res.print();
}


