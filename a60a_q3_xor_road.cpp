#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

class UnionFind{
public:
    int rank[2005];
    int parent[2005];

    UnionFind() {
        for (int i=0;i<2005;i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(int x){
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if (rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if (rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> code(n);
    for(auto &e:code) cin >> e;
    priority_queue<tuple<int,int,int>> pq;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i != j) pq.emplace(code[i]^code[j],i,j);
        }
    }
    UnionFind UF;
    ll ans=0;
    int cnt=0;
    while(!pq.empty()){
        auto [w, u, v] = pq.top();
        pq.pop();
        if (UF.findParent(u) != UF.findParent(v)){
            UF.unionSet(u,v);
            ans += w;
            cnt++;   
        }
        if (cnt == n-1) break;
    }
    cout << ans;

    return 0;
}