#include <iostream>
#include "String.h"
#include <assert.h>
using namespace std;

#define MAX_LEN 1000

int main()
{
	char* s = new char[MAX_LEN];
	cin >> s;
	cout << s << endl;
	MyString str(s);
	str.print();
	MyString child(str);
	child.print();
	MyString father = str;
	father.print();
	cout << "--- len ---" << endl;
	cout << child.len() << endl;
	cout << "--- del_substr ---" << endl;
	int x;
	int y;
	cout << "Input x" << endl;
	cin >> x;
	cout << "Input y" << endl;
	cin >> y;

	father.del_substr(x, y);
	father.print();
	cout << "--- ins ---" << endl;
	int r;
	cout << "Input r" << endl;
	cin >> r;

	char c;
	cout << "Input c" << endl;
	cin >> c;
	child.ins(r, c);
	child.print();
	cout << "--- concat ---" << endl;
	char* w = new char[MAX_LEN];
	cin >> w;
	cout << w << endl;
	MyString cot(w);
	MyString res = str + cot;
	res.print();

	MyString s1 = "s1";//
	s1.print();
	assert(strcmp(s1.get(), "s1") == 0);
	MyString s2 = "s2";
	s2.print();
	assert(strcmp(s2.get(), "s2") == 0);
	MyString s3 = s1 + s2;
	s3.print();
	assert(strcmp(s3.get(), "s1s2") == 0);//
}


