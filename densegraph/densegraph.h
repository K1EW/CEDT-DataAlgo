#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__


#include <vector>
#include <set>
using namespace std;
class DenseGraph{
public:
    DenseGraph() : adjList(vector<set<int>>(3)) {
    }

    DenseGraph(int n_in) : adjList(vector<set<int>>(n_in)) {
    }

    DenseGraph(const DenseGraph& G) {
        adjList = vector<set<int>>(G.adjList.size());
        for (int i=0;i<adjList.size();i++)
            adjList[i] = G.adjList[i];
    }

    void AddEdge(int a, int b) {
        adjList[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        adjList[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        return adjList[a].count(b);
    }

    DenseGraph Transpose() const {
        DenseGraph T(adjList.size());
        for (int i=0;i<adjList.size();i++){
            for (auto v : adjList[i])
                T.adjList[v].insert(i);
        }
        return T;
    }

protected:
    vector<set<int>> adjList;
};
#endif 
