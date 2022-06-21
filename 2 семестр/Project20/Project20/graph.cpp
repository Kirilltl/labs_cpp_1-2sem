#include "graph.h"
#include <iostream>
#include <queue> 
#include <stack> 
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <string> 
using namespace std;
//0 1 1 0 0 0 1
//1 0 1 1 0 0 0
//1 1 0 0 0 0 0
//0 1 0 0 1 0 0
//0 0 0 1 0 1 0
//0 0 0 0 1 0 1
//1 0 0 0 0 1 0
class File
{
private:
    ifstream mfile;
public:
    File(){ mfile = ifstream("C:\\temp\\matr.txt"); }
    ~File(){ mfile.close(); }             
    bool getln(string& str)
    {
        getline(mfile, str);
        return !mfile.eof();
    }
};
Adjmatr Graph::read()
{   
    int n;
    File f;
    string str;
    //f.getln(str)
    while (f.getln(str))
    {       
        istringstream ss(str);
        vector <int> v;
        while (ss >> n) {
            v.push_back(n);
        }
        m.push_back(v);
    }
    return m;
}
void Graph::bfs(int req)
{
    struct Edge {
        int begin;
        int end;
    };
    queue<int> Queue;
    stack<Edge> Edges;
    Edge e;
    vector<int> nodes;
    Adjmatr a;
    nodes.resize(m.size());
    for (unsigned int i = 0; i < m.size(); i++)
        nodes[i] = 0;
    req--;
    Queue.push(0);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (unsigned int j = 0; j < m.size(); j++)
        {
            if (m[node][j] == 1 && nodes[j] == 0)
            {
                Queue.push(j);
                nodes[j] = 1;
                e.begin = node;
                e.end = j;
                Edges.push(e);
                if (node == req)
                    break;
            }           
        }    
        cout <<  node + 1 << endl;
    }
    cout << "how to go to vertex " << req + 1 << endl;
    cout << req + 1;
    while (!Edges.empty()) {
        e = Edges.top();
        Edges.pop();
        if (e.end == req) {
            req = e.begin;
            cout << " <- " << req + 1;
        }
    }
}
