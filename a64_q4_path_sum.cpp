#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int n, m;
int adjMtx[25][25];
int mxw[25];
vector<int> qr(8);

bool search(int u, int sum, int cap, int &k, vector<bool>& vis){
    if (sum > k || sum + cap < k) return false;
    if (sum == k) return true;
    for (int v=0;v<n;v++){
        if (adjMtx[u][v] && !vis[v]){
            vis[v]=true;
            if (search(v, sum+adjMtx[u][v], cap-mxw[v], k, vis))
                return true;
            vis[v]=false;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (auto &k : qr) cin >> k;
    for (int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjMtx[u][v] = adjMtx[v][u] = w;
    }
    int cap = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            mxw[i] = max(mxw[i], adjMtx[i][j]);
        cap += mxw[i];
    }
    for (auto k : qr){
        bool flag = false;
        for (int u=0;u<n;u++){
            vector<bool> vis(n);
            vis[u] = true;
            flag = search(u, 0, cap-mxw[u], k, vis);
            if (flag) break;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}