#ifndef _STRING_H_
#define _STRING_H_
class MyString
{
private:
	char* m_str;
public:
	MyString(const char* s);
	MyString(MyString& string);
	MyString& operator = (MyString& s);
	char* get();
	void set(char* s);
	~MyString();
	void print();
	void del_substr(unsigned int start, unsigned int end);
	void ins(unsigned int pos, char c);
	MyString& operator+(MyString& s);
	void printf();
	int len();
};
#endif
