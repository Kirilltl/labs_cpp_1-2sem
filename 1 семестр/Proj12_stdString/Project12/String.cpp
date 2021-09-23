#include "String.h"
#include <iostream>
using namespace std;
unsigned int length_word(const char* str)
{
	if(!str)
		return 0;
	int res = 0;
	for (int i = 0; str[i] != '\0'; i++)
		res++;
	return res;
}
MyString::MyString(const char* s)
{
	m_str = new char[length_word(s) + 1];
	for (unsigned int i = 0; i < length_word(s) + 1; i++)
	{
		m_str[i] = s[i];
	}
}
MyString::MyString(const MyString& string)
{
	m_str = new char[length_word(string.get()) + 1];
	for (unsigned int i = 0; i < length_word(string.get()) + 1; i++)
	{
		m_str[i] = string.get()[i];
	}
}
char* MyString::get() const
{
	return m_str;
}
MyString& MyString::operator = (const MyString& s)
{
	char* tmp = new char[length_word(s.get()) + 1];
	for (unsigned int i = 0; i < length_word(s.get()) + 1; i++)
	{
		tmp[i] = s.get()[i];
	}
	delete[] m_str;
	m_str = tmp;
	return *this;
}
void MyString::set(char* s)
{
	delete[] m_str;
	m_str = new char[length_word(s)];
	for (unsigned int i = 0; i < length_word(s) + 1; i++)
	{
		m_str[i] = s[i];
	}
}
MyString::~MyString()
{
	delete[] m_str;
}
void MyString::print() const 
{
	cout << m_str << endl;
}
bool MyString::check_polindrom() const
{
	int len = length_word(m_str);
	for (int i = 0; i < len / 2; ++i)
	{
		if (m_str[i] != m_str[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
bool MyString::del_substr(unsigned int start, unsigned int end)
{
	if (!m_str)
	{
		return false;
	}
	if (end < start)
	{
		return false;
	}
	if (end < 0 && start < 0)
	{
		return false;
	}
	if (end > length_word(m_str))
		return false;
	unsigned size = length_word(m_str) - (end - start);
	if (size < 0)
		return false;
	char* tmp = new char[size];
	if (!tmp)
		return false;
	int j = 0;
	for (unsigned int i = 0; i < length_word(m_str) + 1; i++)
	{
		if (i >= start && i <= end)
			continue;
		tmp[j] = m_str[i];
		j++;
	}
	delete[] m_str;
	m_str = tmp;
	return true;
}
bool MyString::ins(unsigned int pos, char c)
{
	if (pos > length_word(m_str))
		return false;
	char* tmp = new char[length_word(m_str) + 2];
	int j = 0;
	for (unsigned int i = 0; i < length_word(m_str) + 2; i++)
	{
		if (i < pos)
		{
			tmp[i] = m_str[j];
			j++;
		}
		else if (i == pos)
			tmp[i] = c;
		else
		{
			tmp[i] = m_str[j];
			j++;
		}
	}
	delete[] m_str;
	m_str = tmp;
	return true;
}
MyString MyString::operator+(const MyString& s)  const
{
	MyString newstr=*this;
	unsigned size = length_word(m_str) + length_word(s.get()) + 1;
	char* tmp = new char[size];
	int j = 0;
	for (unsigned int i = 0; i < length_word(m_str); i++, j++)
	{
		tmp[j] = m_str[i];
	}
	for (unsigned int i = 0; i < length_word(s.get()) + 1; i++, j++)
	{
		tmp[j] = s.get()[i];
	}
	delete[] newstr.m_str;
	newstr.m_str = tmp;
	return newstr;
}                                                                                                                                 
int MyString::len() const
{
	return length_word(m_str);
}

