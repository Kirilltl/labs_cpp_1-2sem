#include <map>
#include <iostream>
#include<fstream>
#include"config.h"
using namespace std;
int main() {
    Config c;
    c.load("C:\\Temp\\conf.txt");
    try
    {
        string p = c.find_str("path");
        cout << p << endl;
        string k = c.find_str("name");
        cout << k << endl;
        c.add("five", "4");
        cout << c.find_str("five") << endl;
    }
    catch (runtime_error& e)
    {
        cout << e.what() << endl;
    }
}