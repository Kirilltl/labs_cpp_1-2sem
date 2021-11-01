#include "graph.h"
#include <iostream>
//#include <queue> 
//#include <stack> 
//#include <fstream> 
//#include <sstream> 
//#include <vector> 
//#include <string> 
using namespace std;
int main()
{
    int req;
    cout << "N = ";
    cin >> req;
    Graph g;
    Adjlist a = g.read();
    g.adjlist2matr(a);
    g.bfs(req);
    return 0;
}