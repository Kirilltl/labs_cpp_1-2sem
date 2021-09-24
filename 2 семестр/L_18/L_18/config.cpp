#include"config.h"
#include<stdexcept>
#include <iostream>
#include<fstream>
using namespace std;

void Config::add(const std::string& key, int val_int)
{
	Value v;
	v.val_int = val_int;
	v.is_int = true;
	m[key] = v;
}
void Config::add(const std::string& key, const std::string& val_str) {
	Value v;
	v.val_str = val_str;
	v.is_int = false;
	m[key] = v;
}
void Config::erase_int(const std::string& key) 
{
	if (m[key].is_int == true) {
		m.erase(key);
	}
	else
	{
		throw runtime_error("key is good but type is wrong");
	}
}

void Config::erase_str(const std::string& key) {
	if (m[key].is_int == false) {
		m.erase(key);
	}
	else
	{
		throw runtime_error("key is good but type is wrong");
	}
}
int Config::find_int(const std::string& key) {
	map<string, Value>::iterator it = m.find(key);
	if (it == m.end())
	{
		throw runtime_error("can not find int");
	}

	if (m[key].is_int == true) {
		return it->second.val_int;
	}
	else
	{
		throw runtime_error("key is good but type is wrong");
	}
}


std::string Config::find_str(const std::string& key) {
	map<string, Value>::iterator it = m.find(key);
	if (it == m.end())
	{
		throw runtime_error("can not find str");
	}

	if (m[key].is_int == false) {
		return it->second.val_str;
	}
	else
	{
		throw runtime_error("key is good but type is wrong");
	}
}
//operator<<; //для вывода на экран
void Config::load(const std::string& filename) {
	ifstream fin;
	fin.open(filename);

	string tmp;
	while (getline(fin, tmp, '\n'))
	{
		string key = tmp.substr(0, tmp.find('='));
		string val = tmp.substr(tmp.find('=') + 1, tmp.size());
		

		
		int val_int = atoi(val.c_str());
		cout << val_int << endl;

		if (val_int == 0 && val != "0")
		{
			cout << "eto stroka!" << endl;
			m[key].val_str = val;
			m[key].is_int = false;
		}
		else
		{
			cout << "eto chislo" << endl;
			m[key].val_int = val_int;
			m[key].is_int = true;
		}

		cout << "=========" << endl;
		
	}

}

//operator<<
//{
//	for (map <string, Value> ::iterator it = m.begin(); it != m.end(); it++) {
		//cout << "m[" << it->first << "] = " << it->second << endl;
	//}
//}
void Config::save(const std::string& filename) {
	ofstream fout;
	fout.open(filename);
	
	for (map <string, Value> ::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second.is_int == true)
			fout << it->first << "=" << it->second.val_int << endl;
		else
			fout << it->first << "=" << it->second.val_str << endl;
	}

	fout.close();
}