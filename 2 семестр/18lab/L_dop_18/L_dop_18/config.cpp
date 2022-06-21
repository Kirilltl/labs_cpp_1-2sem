#include"config.h"
#include<stdexcept>
#include <iostream>
#include<fstream>
#include <utility>
using namespace std;
void Config::add(const std::string& key, const std::shared_ptr<Value>& value)
{
	m[key] = value;
}

std::string Config::find(const std::string& key) {
	map<string, std::shared_ptr<Value> >::iterator it = m.find(key);
	if (it == m.end())
	{
		cout<<"can not find int" <<endl;
	}

	return it->second->to_string();
}

void Config::erase(const std::string& key)
{	
	m.erase(key);		
}


void Config::print() {

	for (map <string, std::shared_ptr<Value> > ::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << ">>>> " << it->first << " = " << it->second->to_string() << endl;
	}
}

void Config::save(const std::string& filename) {
	ofstream fout;
	fout.open(filename);

	for (map <string, std::shared_ptr<Value> > ::iterator it = m.begin(); it != m.end(); it++)
	{
		fout << it->second->get_type() <<" "<< it->first << "=" << it->second->to_string() << endl;
	}

	fout.close();
}

void Config::load(const std::string& filename) {
	ifstream fin;
	fin.open(filename);

	string tmp;
	while (getline(fin, tmp, '\n'))
	{
		int space = tmp.find(" ", 0 );
		int equality = tmp.find("=", 0);

		string type = tmp.substr(0, space);
		string key = tmp.substr(space + 1 , equality-space-1);
		string val = tmp.substr(equality + 1, tmp.size());

		if (type == "int")
		{
			std::shared_ptr<Value> v(new IntValue);
			v->from_string(val);
			m[key] = v;
		}
		//v = new SetValue(); // TODO! Smart pointer!
		else if (type == "set")
		{
			std::shared_ptr<Value> v(new SetValue);
			v->from_string(val);
			m[key] = v;
		}
		else if (type == "string")
		{
			std::shared_ptr<Value> v(new StrValue);
			v->from_string(val);
			m[key] = v;
		}
		else
		{
			cout << "unknown type: " << type << endl;
			continue;
		}
	}
	fin.close();
}


/*
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
void Config::load(const std::string& filename) {
	ifstream fin;
	fin.open(filename);

	string tmp;
	while (getline(fin, tmp, '\n'))
	{
		string key = tmp.substr(0, tmp.find('='));
		string val = tmp.substr(tmp.find('=') + 1, tmp.size());
		int val_int = atoi(val.c_str());
		if (val_int != 0)
			cout << val_int << endl;
		if (val_int == 0 && val != "0")
		{
			m[key].val_str = val;
			m[key].is_int = false;
		}
		else
		{
			m[key].val_int = val_int;
			m[key].is_int = true;
		}
	}
	fin.close();
}
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
}*/