#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int n, m;
vector<vector<int>> ans;
vector<int> con(25, -1);

void perm(vector<int> &res, vector<bool> &used){
    if (res.size() == n){
        ans.push_back(res);
        return;
    }
    for (int i=0;i<n;i++){
        if (!used[i] && (con[i] == -1 || used[con[i]])){
            res.push_back(i);
            used[i] = true;
            perm(res, used);
            used[i] = false;
            res.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--){
        int a, b;
        cin >> a >> b;
        con[b] = a;
    }
    vector<int> res;
    vector<bool> used(n);
    perm(res,used);
    sort(ALL(ans));
    for (auto v : ans){
        for (auto e : v) cout << e << " ";
        cout << "\n";
    }

    return 0;
}