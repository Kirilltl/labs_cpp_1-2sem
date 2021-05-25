#include <iostream>
#include "String.h"
using namespace std;
int main()
{
	MyString str("weststring");
	str.print();
	MyString child(str);
	child.print();
	MyString father = str;
	father.print();
	cout << "--- len ---" << endl;
	child.len();
	child.printf();
	cout << "--- del_substr ---" << endl;
	father.del_substr(4, 9);
	father.print();
	cout << "--- ins ---" << endl;
	child.ins(7, '%');
	child.print();
	cout << "--- concat ---" << endl;
	MyString cat("cats");
	MyString cot("cots");
	cat = cat + cot;
	cat.print();
}


