#include <iostream>
#include "String.h"
#include <assert.h>
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
	cout << child.len() << endl;
	cout << "--- del_substr ---" << endl;
	father.del_substr(4, 9);
	father.print();
	cout << "--- ins ---" << endl;
	child.ins(7, '%');
	child.print();
	cout << "--- concat ---" << endl;
	MyString cot("cots");
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


