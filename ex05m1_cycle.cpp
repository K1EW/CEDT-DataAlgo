#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int t, n, e;
vector<int> adjList[1005];
vector<bool> vis(1005);

bool dfs(int u, int prev){
    vis[u] = true;
    bool ret = false;
    for (auto v : adjList[u]){
        
        if (vis[v] && v != prev) return true;
        if (!vis[v])
            ret = ret || dfs(v, u); 
    }
    return ret;
}

void solve(){
    cin >> n >> e;
    for (int i=0;i<n;i++){
        adjList[i].clear();
        vis[i] = false;
    }
    for (int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool ok = false;
    for (int u=0;u<n;u++){
        if (!vis[u]) ok = ok || dfs(u, -1);
    }
    cout << (ok ? "YES" : "NO");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }

    return 0;
}