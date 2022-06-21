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
	if (child.check_polindrom())
		cout << "Word "<< child.get() <<" is polindrom";
	else
		cout << "Word "<< child.get() <<" isn't polindrom";
	printf("\n");
	cout << "--- del_substr ---" << endl;
	int x;
	int y;
	cout << "Input first index" << endl;
	cin >> x;
	cout << "Input last index" << endl;
	cin >> y;
	if (father.del_substr(x, y))
		father.print();
	else
		printf("ERROR\n");
	cout << "--- ins ---" << endl;
	int r;
	cout << "Input index" << endl;
	cin >> r;
	char c;
	cout << "Input symbol" << endl;
	cin >> c;
	if (child.ins(r, c))
		child.print();
	else
		printf("ERROR\n");
	cout << "--- concat ---" << endl;
	char* w = new char[MAX_LEN];
	cout << "Enter the string to add" << endl;
	cin >> w;
	MyString cot(w);
	if (cot.check_polindrom())
		cout << "Word "<< cot.get() <<" is polindrom";
	else
		cout << "Word "<< cot.get() <<" isn't polindrom";
	printf("\n");
	MyString res = str + cot;
	res.print();
	if (res.check_polindrom())
		cout << "Word "<< res.get() <<" is polindrom";
	else
		cout << "Word "<< res.get() <<" isn't polindrom";
	printf("\n");
	return 0;
}


