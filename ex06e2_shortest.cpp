#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, s;
    cin >> n >> e >> s;
    vector<tuple<int,int,int>> edges;
    for (int i=0;i<e;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }
    vector<int> dist(n+5, 1e8);
    dist[s] = 0;
    for (int i=0;i<n-1;i++){
        for (auto [w, u, v] : edges){
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    for (auto [w, u, v] : edges){
        if (dist[u] + w < dist[v]){
            cout << -1;
            return 0;
        }
    }
    for (int i=0;i<n;i++){
        cout << dist[i] << " ";
    }
    return 0;
}