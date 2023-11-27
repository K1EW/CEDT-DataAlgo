#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

vector<int> adjList[1005];

int n, e, k;

int bfs(int s){
    int ret = 0;
    queue<pair<int,int>> q;
    q.push({s,0});
    vector<bool> vis(1005);
    while (!q.empty()){
        auto [u, c] = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        if (c <= k)
            ret++;
        if (c > k) continue;
        for (auto v : adjList[u]){
            if (!vis[v])
                q.push({v, c+1});
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx=0,ans=0;
    cin >> n >> e >> k;
    while (e--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i=0;i<n;i++){
        int cnt = bfs(i);
        mx = max(mx, cnt);
    }
    cout << mx;

    return 0;
}