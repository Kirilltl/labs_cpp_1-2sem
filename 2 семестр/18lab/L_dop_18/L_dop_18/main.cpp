#include <map>
#include <iostream>
#include<fstream>
#include"config.h"
using namespace std;
int main() {
    
    /*Config c;
    c.load("C:\\Temp\\setting.txt");
    c.print();*/

    
    Value* value = new IntValue();
    value->set(15);
    cout << value->get<int>() << endl;
    cout << value->getType() << endl;
    cout << "getString: '" << value->getString() << "'" << endl;
   
    
}