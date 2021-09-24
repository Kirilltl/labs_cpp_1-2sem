#ifndef CONFIG_H
#define CONFIG_H
#include<string>
#include<map>

struct Value {
	int val_int;
	std::string val_str;
	bool is_int;
};
class Config
{
private:
	std::map<std::string, Value> m;
public:
	void add(const std::string& key, int val_int);
	void add(const std::string& key, const std::string& val_str);
	void erase_int(const std::string& key);
	void erase_str(const std::string& key);
	int find_int(const std::string& key);
	std::string find_str(const std::string& key);
	//operator<<; //для вывода на экран
	void load(const std::string& filename); //загрузка из файла
	void save(const std::string& filename);
};

#endif
