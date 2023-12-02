#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int adjMat[n+5][n+5];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin >> adjMat[i][j];
    vector<int> dist(n+5,INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()){
        auto [c, u] = pq.top();
        pq.pop();
        for (int v=1;v<=n;v++){
            if (adjMat[u][v] > 0 && dist[v] > dist[u] + adjMat[u][v]){
                dist[v] = dist[u] + adjMat[u][v];
                pq.emplace(dist[v], v);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++)
        ans = max(ans, dist[i]);
    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}