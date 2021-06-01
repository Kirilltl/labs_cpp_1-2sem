#include "String.h"
#include <iostream>
using namespace std;
unsigned int length_word(const char* str)
{
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
MyString::MyString(MyString& string)
{
	m_str = new char[length_word(string.get()) + 1];
	for (unsigned int i = 0; i < length_word(string.get()) + 1; i++)
	{
		m_str[i] = string.get()[i];
	}
}
char* MyString::get()
{
	return m_str;
}
MyString& MyString::operator = (MyString& s)
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
void MyString::print()
{
	cout << m_str << endl;
}
void MyString::del_substr(unsigned int start, unsigned int end)
{
	if (end == start)
		return;
	if (!m_str)
		return;
	if (end < start)
		return;
	if (end > length_word(m_str))
		return;
	unsigned size = length_word(m_str) - (end - start);
	if (size < 0)
		return;
	char* tmp = new char[size];
	if (!tmp)
		exit(1);
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
}
void MyString::ins(unsigned int pos, char c)
{
	if (pos > length_word(m_str))
		exit(1);
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
}
MyString& MyString::operator+(MyString& s)
{
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
	delete[] m_str;
	m_str = tmp;
	return *this;
}
void MyString::printf()
{
	int res = length_word(m_str);
	cout << res << endl;
}
int MyString::len()
{
	return length_word(m_str);
}
//#include "String.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//MyString::MyString(const char* s)
//{
//	m_str = new char[strlen(s) + 1];
//	for (unsigned int i = 0; i < strlen(s) + 1; i++)
//	{
//		m_str[i] = s[i];
//	}
//}
//MyString::MyString(MyString& string)
//{
//	//MyString ress(*this);
//	m_str = new char[strlen(string.get()) + 1];
//	for (unsigned int i = 0; i < strlen(string.get()) + 1; i++)
//	{
//		m_str[i] = string.get()[i];
//	}
//
//}
//char* MyString::get()const 
//{
//	return m_str;
//}
//MyString MyString::operator = (const MyString& s)
//{
//	char* tmp = new char[strlen(s.get()) + 1];
//	for (unsigned int i = 0; i < strlen(s.get()) + 1; i++)
//	{
//		tmp[i] = s.get()[i];
//	}
//	delete[] m_str;
//	m_str = tmp;
//	return *this;
//}
//void MyString::set(char* s)
//{
//	delete[] m_str;
//	m_str = new char[strlen(s)];
//	for (unsigned int i = 0; i < strlen(s) + 1; i++)
//	{
//		m_str[i] = s[i];
//	}
//}
//MyString::~MyString()
//{
//	delete[] m_str;
//}
//void MyString::print()
//{
//	cout << m_str << endl;
//}
//void MyString::del_substr(unsigned int start, unsigned int end)
//{
//	if (end == start)
//		return;
//	if (!m_str)
//		return;
//	if (end < start)
//		return;
//	if (end > strlen(m_str))
//		return;
//	unsigned size = strlen(m_str) - (end - start);
//	if (size < 0)
//		return;
//	char* tmp = new char[size];
//	if (!tmp)
//		exit(1);
//	int j = 0;
//	for (unsigned int i = 0; i < strlen(m_str) + 1; i++) 
//	{
//		if (i >= start && i <= end)
//			continue;
//		tmp[j] = m_str[i];
//
//		j++;
//	}
//	delete[] m_str;
//	m_str = tmp;
//}
//void MyString::ins(unsigned int pos, char c)
//{ 
//	if (pos > strlen(m_str))
//		exit(1);
//	char* tmp = new char[strlen(m_str) + 2];
//	int j = 0;
//	for (unsigned int i = 0; i < strlen(m_str) + 2; i++)
//	{
//		if (i < pos)
//		{
//			tmp[i] = m_str[j];
//			j++;
//		}
//		else if (i == pos)
//			tmp[i] = c;
//		else
//		{
//			tmp[i] = m_str[j];
//			j++;
//		}
//	}
//	delete[] m_str;
//	m_str = tmp;
//}
//			// Сейчас он перезатирает исходный объект, а должен сначала скопировать исходный и уже скопированный изменить и вернуть его.
//			// Для этого вначале нужно используя конструктор копий копернуть начальный объект, а затем поменять RV (return value) на скопированный
//			// (и перезатирать внутри, соответсвтенно его значения, а не исходника)
//MyString MyString::operator+(const MyString& s)const
//{
//	unsigned size = strlen(m_str) + strlen(s.get()) + 1;
//	
//	char* tmp = new char[size];
//	int j = 0;
//	for (unsigned int i = 0; i < strlen(m_str); i++, j++)
//	{
//		tmp[j] = m_str[i];
//	}
//	for (unsigned int i = 0; i < strlen(s.get()) + 1; i++, j++)
//	{
//		tmp[j] = s.get()[i];
//	}
//	delete[] m_str;
//	m_str = tmp;
//								/*MyString ress= *this;
//								int j = 0;
//								for (unsigned int i = 0; i < strlen(m_str); i++, j++)
//								{
//									ress.m_str[j] = m_str[i];
//								}
//								for (unsigned int i = 0; i < strlen(s.get()) + 1; i++, j++)
//								{
//									ress.m_str[j] = s.get()[i];
//								}
//								return ress;*/
//	
//}
//void MyString::printf()
//{
//	int res = strlen(m_str);
//	cout << res << endl;
//}
//int MyString::len()
//{
//	return strlen(m_str);
//}
