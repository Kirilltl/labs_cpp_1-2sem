#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
    int req=0;
    cout << "N = ";
    cin >> req;
    Graph g;
    g.read();
    g.bfs(req);
    return 0;
}