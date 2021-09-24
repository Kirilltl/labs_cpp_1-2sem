#include <map>
#include <iostream>
#include<fstream>
#include"config.h"
using namespace std;

int main() {
    Config c;
    c.load("C:\\Temp\\config.txt");
   

    //cout << c << endl;

    cout << "---------------------------  " << endl;
    try
    {
        string i = c.find_str("path");
        cout << i << endl;
        c.add("five", "78");
        c.add("six", 78);

        cout << c.find_str("five") << endl;

    }
    catch (runtime_error& e)
    {
        cout << e.what() << endl;
    }


}