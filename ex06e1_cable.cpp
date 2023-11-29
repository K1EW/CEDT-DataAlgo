#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

const int MXN = 1005;

class UnionFind {
public:
    int rank[MXN];
    int parent[MXN];

    UnionFind() {
        for (int i=0;i<MXN;i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int findParent(int u){
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionNode(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};


typedef tuple<int,int,int> tiii;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans=0;
    cin >> n;
    vector<tiii> edges;
    for (int i=0;i<n-1;i++){
        int w;
        for (int k=i+1;k<=n-1;k++){
            cin >> w;
            edges.push_back({w, i, k});
        }
    }
    sort(ALL(edges));
    UnionFind UF;
    for (auto &[w, u, v] : edges){
        if (UF.findParent(u) != UF.findParent(v)){
            UF.unionNode(u, v);
            ans += w;
        }
    }
    cout << ans;

    return 0;
}