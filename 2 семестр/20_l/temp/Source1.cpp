#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;
const int INF = INT_MAX;
vector< vector<pair<int, int>> > graph; 
vector<int> ans;
vector<int> pr;

void check()
{
    int n=0;
    ifstream file("C:\\temp\\input.txt");
    string str;

    while (getline(file, str))
    {
        n++;
    }
    file.close();

    cout << n << endl;
    graph.resize(n);
    ans.resize(n);
    pr.resize(n);
    cout << n << endl;

}


void read()
{
    int t = 0;
    int n;
    ifstream file("C:\\temp\\input.txt");
    string str;

    while (getline(file, str))
    {
        istringstream ss(str);

        vector <int> v;
        while (ss >> n) {
            v.push_back(n);
        }
    
        pair<int, int> p(v[1], v[2]);
        graph[ v[0] ].push_back( p );
//        cout << " " << p.first << " " << p.second << endl;
//        cout << "============== " << endl;


    }
    file.close();

    //for (int i = 0; i < 5; i++)
    //{
    //    vector<pair<int, int>> vp = graph[i];
    //    for (int j = 0; j < size(vp); j++)
    //    {
    //        pair<int, int> p = vp[j];
    //        cout << p.first << " " << p.second << endl;
    //    }
    //    cout << "============== " << endl;
    //}

}

void calc()
{

    int n = 5;
    int start = 0;
    int end = 4;

    for (int i = 0; i < n; i++) {
        ans[i] = INF;
        pr[i] = -1;   //Значение, обозначающее что из этой вершины возвращаться некуда
    }

    ans[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({ 0, start });

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (ans[v] < dst) {
            continue;
        }

        for (pair<int, int> e : graph[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u]) {
                ans[u] = n_dst;
                pr[u] = v;
                q.push({ n_dst, u });
            }
        }
    }

    vector<int> path;

    int cur = end;
    path.push_back(cur);

    while (pr[cur] != -1) {
        cur = pr[cur];
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path between vertices " << start + 1 << " and " << end + 1 << " is: " << endl;

    for (int v = 0; v < path.size(); v++)
    {
        cout << path[v] + 1 << " ";
    }
    for (int i = 0; i < n; i++) {
        cout << "Shortest path from " << start + 1 << " to " << i + 1 << " has length " << ans[i] << endl;
    }

}




int main() {

    check();
    read();
    calc();
    

}