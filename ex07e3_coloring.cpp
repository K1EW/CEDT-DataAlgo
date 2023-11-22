#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

vector<int> adjList[55];
vector<bool> visited(55);
int n, e;

bool coloring(int u, int &m, vector<int> &color){
    if (u == n) return true;
    for (int c = 1; c <= m; c++){
        bool ok = true;
        for (auto v : adjList[u])
            ok = ok && c != color[v];
        if (ok){
            color[u] = c;
            if (coloring(u+1, m, color)) return true;
            color[u] = 0;
        } 
    }
    return false;
}

bool check(int &m){
    vector<int> color(n);
    return coloring(0, m, color);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    for (int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int l=1,r=n, ans=n;
    while (l<=r){
        int m = l + (r - l)/2;
        if (check(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << ans;

    return 0;
}