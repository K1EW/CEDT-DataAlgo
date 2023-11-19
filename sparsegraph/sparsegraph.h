#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class SparseGraph{
public:
    SparseGraph() : adjList(vector<vector<int>>(3)) {
    }

    SparseGraph(int n_in) : adjList(vector<vector<int>>(n_in)) {
    }

    SparseGraph(const SparseGraph& G) {
        adjList.clear();
        adjList = vector<vector<int>>(G.adjList.size());
        for (int i=0;i<adjList.size();i++){
            adjList[i] = G.adjList[i];
        }
    }

    void AddEdge(int a, int b) {
        auto it = find(adjList[a].begin(), adjList[a].end(), b);
        if (it != adjList[a].end()) return;
        adjList[a].push_back(b);
    }

    void RemoveEdge(int a, int b) {
        auto it = find(adjList[a].begin(), adjList[a].end(), b);
        if (it != adjList[a].end()) adjList[a].erase(it);
    }

    bool DoesEdgeExist(int a, int b) const {
        auto it = find(adjList[a].begin(), adjList[a].end(), b);
        return it != adjList[a].end();
    }

    SparseGraph Transpose() const {
        SparseGraph T(adjList.size());
        for (int i = 0; i < adjList.size(); ++i) {
            for (int v : adjList[i]) {
                T.adjList[v].push_back(i);
            }
        }
        return T;
    }

protected:
    vector<vector<int>> adjList;
};
#endif