#include <map>
#include <iostream>
#include<fstream>
#include"config.h"
using namespace std;
int main() {
    Config c;
    c.load("C:\\Temp\\setting.txt");
    c.print();
}

























//v = new SetValue(); // TODO! Smart pointer!
/*std::shared_ptr<Value> v1(new IntValue);
    std::shared_ptr<Value> v2(new IntValue);
    std::shared_ptr<Value> v3(new IntValue);

    v1->from_string("123");
    v2->from_string("345");
    v3->from_string("1");

    c.add("color1", v1);
    c.add("color2", v2);
    c.add("color3", v3);
    c.erase("color2");

    c.print();
    c.save("C:\\Temp\\setting.txt");*/