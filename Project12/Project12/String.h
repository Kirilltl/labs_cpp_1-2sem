#ifndef _STRING_H_
#define _STRING_H_
class MyString
{
private:
	char* m_str;
public:
	MyString(const char* s);
	MyString(const MyString& string);
	MyString& operator = (const MyString& s);
	char* get() const;
	void set(char* s);
	~MyString();
	void print() const;
	void del_substr(unsigned int start, unsigned int end);
	void ins(unsigned int pos, char c);
	MyString operator+(const MyString& s)  const;
	int len() const;
};
#endif