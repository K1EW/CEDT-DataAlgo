#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

vector<int> adjList[10005];
vector<bool> vis(10005);
int n, e;

void dfs(int u){
    vis[u] = true;
    for (auto v : adjList[u])
        if (!vis[v])
            dfs(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    while (e--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans;

    return 0;
}