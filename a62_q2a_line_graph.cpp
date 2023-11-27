#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

vector<int> adjList[100005];
vector<bool> vis(100005);
int n, e, cnt = 0, mxDeg = 0;

int dfs(int u){
    vis[u] = true;
    cnt++;
    mxDeg = max(mxDeg, (int)adjList[u].size());
    int ret = adjList[u].size();
    for (auto v : adjList[u]){
        if (!vis[v]){
            ret += dfs(v);
        }
    }
    return ret;
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
    for (int i=0;i<n;i++){
        cnt = 0;
        mxDeg = 0;
        if (!vis[i]){
            int edges = dfs(i)/2;
            if (mxDeg <= 2){
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}