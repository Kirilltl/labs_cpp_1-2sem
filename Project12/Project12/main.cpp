#include <iostream>
using namespace std;

class String
{
private:
	char* m_str;
	

public:
	// constructor
	String(const char* s)
	{
		m_str = new char[strlen(s) + 1];
		strcpy(m_str, s);
	}

	// copy constructor
	String(String& string)
	{
		m_str = new char[strlen(string.get()) + 1];
		strcpy(m_str, string.get());
	}

	// getter
	char* get()
	{
		return m_str;
	}
	// operator =
	String& operator = (String& string)
	{
		m_str = new char[strlen(string.get()) + 1];
		strcpy(m_str, string.get());
	}
	// setter
	void set(char* s)
	{
		delete[] m_str;
		m_str = new char[strlen(s)];
		strcpy(m_str, s);
	}
	
	~String()
	{
		delete [] m_str;
	}

	void print()
	{
		cout << m_str << endl;
	}

	void del_substr(unsigned int start,unsigned int end)
	{ 
		if (end > start) 
			return;
		if (end > strlen(m_str))
			return;
		char* tmp = new char[strlen((m_str) - (end-start))];
		for (unsigned int i = 0; i < strlen(m_str); i++) // и был интовым и было предупреждение несовместимости поэтому и теперь unsigned
		{
			if (i >= 4 || i <= 8)
				continue;
			tmp[i] = m_str[i];
		}
		delete[] m_str;
		m_str = tmp;
	}
	
	
};
	string str_conc(string &n, string &d)//конкатенация
	{
		cin >> n >> d;
		d = n + d;
		//return n;
		return d;
	}
	
	int res = 0;
	int length_word(string &a) // dlina stroki
	{
		
		cin >> a;
		for (int i = 0; a[i] != '\0'; i++)
			res++;
		return res;
	}
	
	void ins()
	{ // vstavka simvolov
		char w[20] = "hello"; 
		printf("%s\n", w);
		for (int i = 19; i > 3; i--)
			w[i] = w[i - 1];
			w[3] = '7';
			printf("%s\n", w);
	}
int main()
{
	String str("It's raining");
	str.print();

	String child(str);
	child.print();

	String father = str;
	father.print();

	father.del_substr(4, 8);
	father.print();

	string n;
	string d;
	str_conc(n,d);
	cout << "Result: " << d;
	cout << "\n";
	
	string a;
	length_word(a);
	cout << "len: " << res;
	cout << "\n";

	//char* w = "hello";
	ins();
}


