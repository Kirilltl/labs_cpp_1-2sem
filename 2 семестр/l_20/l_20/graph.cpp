#include "graph.h"
#include <iostream>
#include <queue> 
#include <stack> 
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <string> 
using namespace std;
void Graph::adjlist2matr(const Adjlist& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "a[" << i << "]: ";
		for (int j = 0; j < a[i].size(); j++)
			cout  <<  a[i][j] << " ";
		cout << endl;
	}	
	m.resize(a.size());
	for (int i = 0; i < a.size(); i++)
	{
		m[i].resize(a.size());
	}
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			int current = a[i][j];
			m[i][current] = 1;
		}
	}
	cout << endl;
}

Adjlist Graph::read()
{
    int t = 0;
    int n;
    Adjlist a;
    ifstream file("C:\\temp\\input.txt");
    string str;

    while (getline(file, str))
    {
        istringstream ss(str);

        vector <int> v;
        while (ss >> n) {
            v.push_back(n);
        }
        a.push_back(v);
    }
    file.close();
    for (int i = 0; i < a.size(); i++)
    {
        for (unsigned j = 0; j < a[i].size(); j++)
            if (a[i][j] >= a.size()) {
                cout << "error" << endl;
                exit(1);
            }
    }
    return a;
}

void Graph::bfs2(int req)
{
    struct Edge {
        int begin;
        int end;
    };
    queue<int> Queue;
    stack<Edge> Edges;   
    Edge e;
    vector<int> nodes;
    nodes.resize(m.size()); 
    for (int i = 0; i < m.size(); i++) 
        nodes[i] = 0;    
    req--;
    Queue.push(0);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2; 
        for (int j = 0; j < m.size(); j++)
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
        cout << node + 1 << endl; 
    }
    cout << "how to go to this vertex " << req + 1 << endl;
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
