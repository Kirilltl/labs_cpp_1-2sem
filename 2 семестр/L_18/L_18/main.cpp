#include <map>
#include <iostream>
#include<fstream>
using namespace std;

int main() {
    //map < <L>, <R> > <им€>;  люч Ч строка, значение Ч число.
    //map <тип данных> :: iterator <им€>; it Ч итератор. „тобы обратитс€ к ключу: it->first.   значению €чейки: it->second.
    //Ќельз€ измен€ть значение ключа, а значение €чейки легко. ƒл€ увеличени€ или уменьшени€ можно использовать инкремент или декремент.
    map <string, int> m = { {"first", 1},
                                    {"second", 2},
                                    {"three", 3},
                                    {"four", 4} };
    ofstream fout;
    fout.open("C:\\github\\labs\\2 семестр\\L_18\\Debug\\l18.txt");
    fout << m["first"] << " " << m["second"] << " " << m["three"] << " " << m["four"] << endl;
    fout << "\n";
    map <string, int> ::iterator it = m.begin();
    for (int i = 0; it != m.end(); it++, i++)
        fout << i << ") " << it->first << " " << it->second << endl;
    fout.close();
    
    
    /*cout << "before\n";
    cout << m["first"];
    m["first"] = 55;
    cout << "\nafter\n";
    cout << m["first"];
    cout << "\n";

    m.erase("second");
    m.erase("first");
    map <string, int> ::iterator it = m.begin();
    for (int i = 0; it != m.end(); it++, i++)
        cout << i << ") " << it->first << " " << it->second << endl;*/
    return 0;
  /*map <string, string> m = { {"first", "1"},
                                    {"second", "2"},
                                    {"three", "3"},
                                    {"four", "4"} };

    map <string, string> ::iterator it = m.begin();
    for (int i = 0; it != m.end(); it++, i++)
        cout << i << ") " << it->first << " " << it->second << endl;
    cout << "\n";

    cout << m["first"] << " " << m["second"] << " " << m["three"] << " " << m["four"] << endl;
    cout << "\n";

    map <string, string> v = { {"1", "first"},{"3", "three"} };
    cout << v["1"] << " " << v["3"] << endl;
    return 0;
    */
}