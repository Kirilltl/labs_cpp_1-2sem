#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
typedef std::vector<std::vector<int> > Adjlist;
typedef std::vector<std::vector<int> > Matrix;
class Graph {
private:
    Matrix m;    
public:   
    Graph() {	}
    void adjlist2matr(const Adjlist& a);
    Adjlist read();
    void bfs2(int req);
};
#endif