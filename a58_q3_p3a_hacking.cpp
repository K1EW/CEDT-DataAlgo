#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adjList[n];
    vector<int> dist(n,INT_MAX);
    vector<int> c(n);
    queue<pair<int,int>> q;
    vector<int> temp(k);
    for (auto &e : temp) cin >> e;
    for (auto &e : c) cin >> e;
    for (auto e : temp) q.emplace(c[e], e);
    while(m--){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    while(!q.empty()){
        auto [t, u] = q.front();
        q.pop();
        dist[u] = min(dist[u], t);
        for (auto v : adjList[u]){
            if (t + c[v] < dist[v]){
                q.emplace(t + c[v], v);
            }
        }
    }
    cout << *max_element(dist.begin(),dist.end());

    return 0;
}