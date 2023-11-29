#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

vector<int> adjList[100005];
vector<bool> vis(100005);
vector<int> path;
int ans = 1;

void dfs(int u, int prev){
    vis[u] = true;
    for (auto v : adjList[u]){
        if (vis[v] && prev != v){
            ans = max(ans,(int)(path.size() - (find(ALL(path), v) - path.begin()))); 
            continue;
        }
        if (!vis[v]){
            path.push_back(v);
            dfs(v, u);
            path.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    path.push_back(0);
    dfs(0, 0);
    cout << ans;

    return 0;
}