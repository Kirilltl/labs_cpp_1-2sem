#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
typedef std::vector<std::vector<int>> Adjmatr;
typedef std::vector<std::vector<int>> Matrix;
class Graph {
private:
    Matrix m;
public:
    Adjmatr read();
    void bfs(int req);
};
#endif
