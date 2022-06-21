#ifndef CONFIG_H
#define CONFIG_H
#include<string>
#include<sstream>
#include <set>
#include<iostream>
#include<map>
#include<iostream>
#include <sstream>
using namespace std;

class Value
{
public:
	// setter:
	template <class T>
	void set(const T& v) { holder = new Holder<T>(v); }
	// getter:
	template <class T>
	T get() { return ((Holder<T>*)holder)->val; }
	virtual ~Value() {}
	virtual std::string getType() = 0;
	virtual std::string getString() = 0;
private:
	template <class T>
	struct Holder // it just holds the value of a concrete type
	{
		Holder(const T& v) { val = v; }
		T val;
	};
protected:
	void* holder;
};
class IntValue : public Value
{
public:
	~IntValue() { delete (Holder<int>*)holder; }
	virtual std::string getType() { return "type is IntValue"; };
	virtual std::string getString() {
		stringstream ss;
		ss << get<int>();
		return ss.str();
	}
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
