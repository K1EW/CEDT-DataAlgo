#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int,int>> adjList[705];
    int n, c12;
    cin >> n >> c12;
    adjList[1].push_back({2, c12});
    adjList[2].push_back({1, c12});
    for (int i=3;i<=n;i++){
        int k;
        cin >> k;
        while(k--){
            int v, w;
            cin >> v >> w;
            adjList[i].push_back({v,w});
            adjList[v].push_back({i,w});
        }
        vector<int> dist(n+5, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0, 1);
        while(!pq.empty()){
            auto [c, u] = pq.top();
            pq.pop();
            for (auto [v, w] : adjList[u]){
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        cout << dist[2] << " ";
    }

    return 0;
}