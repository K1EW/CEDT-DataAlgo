#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n+5];
    vector<int> co(n), ci(n);
    for (auto &e : ci) cin >> e;
    for (auto &e : co) cin >> e;
    while (m--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto [c, u] = pq.top();
        pq.pop();
        for (auto v : adjList[u]){
            if (dist[v] > dist[u] + co[u] + ci[v]){
                dist[v] = dist[u] + co[u] + ci[v];
                pq.emplace(dist[v], v);
            }
        }
    }
    for (auto e : dist) cout << (e == INT_MAX ? -1 : e) << " ";

    return 0;
}