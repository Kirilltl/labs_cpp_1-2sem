#ifndef CONFIG_H
#define CONFIG_H
#include<string>
#include<sstream>
#include <set>
#include<iostream>
#include<map>
struct Value
{
	virtual std::string get_type() const = 0;
	virtual std::string to_string() const = 0;
	virtual void from_string(const std::string& str) = 0;
};

struct IntValue : public Value
{
	IntValue() { val = 0; }
	virtual std::string get_type() const {
		return "int";
	}
	virtual std::string to_string() const {
		char str[6];
		_itoa(val, str, 10);
		return std::string(str);
	}
	virtual void from_string(const std::string& str) {
		val = atoi(str.c_str());
	}
private:
	int val;
};

struct SetValue : public Value
{
	virtual std::string get_type() const {
		return "set";
	}
	virtual std::string to_string() const {
		std::stringstream ss;
		for (std::set<int>::iterator it = val.begin(); it != val.end(); it++)
		{
			ss << *it << ",";
		}
		return ss.str().substr(0, ss.str().size() - 1);
	}
	virtual void from_string(const std::string& str) {
		int start = 0;
		for (int i = 1; i < 10; i++) {
			int pos = str.find(",", start);
			std::string res = str.substr(start, pos - start);
			if (pos == std::string::npos)
			{
				val.insert(atoi(res.c_str()));
				break;
			}
			val.insert(atoi(res.c_str()));
			start = pos + 1;
		}
	}
private:
	std::set<int> val;
};

struct StrValue : public Value
{
	StrValue() { val = ""; }
	virtual std::string get_type() const {
		return "string";
	}
	virtual std::string to_string() const {
		return val;
	}
	virtual void from_string(const std::string& str) {
		val = str;
	}
private:
	std::string val;
};

class Config
{
private:
	std::map<std::string, std::shared_ptr<Value> > m;
public:
	void add(const std::string& key, const std::shared_ptr<Value>& val);
	void print();
	void erase(const std::string& key);
	std::string find(const std::string& key);
	void load(const std::string& filename);
	void save(const std::string& filename);
};
#endif
