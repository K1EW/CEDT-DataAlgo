#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int n, m;
vector<vector<int>> ans;
vector<int> con(25, -1);

void perm(int &cnt, vector<int> &res, vector<int> &used){
    if (cnt + res.size() < n) return;
    if (res.size() == n){
        ans.push_back(res);
        return;
    }
    for (int i=0;i<n;i++){
        if (used[i] == 0){
            cnt--;
            used[i] += 1;
            if (con[i] != -1){
                cnt -= used[con[i]] == 0;
                used[con[i]] += 1;
            } 
            res.push_back(i);
            perm(cnt, res, used);
            res.pop_back();
            if (con[i] != -1){
                cnt += used[con[i]] == 1;
                used[con[i]] -= 1;
            }
            cnt++;
            used[i] -= 1;
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
    vector<int> used(n);
    int cnt=n;
    perm(cnt,res,used);
    sort(ALL(ans));
    for (auto v : ans){
        for (auto e : v) cout << e << " ";
        cout << "\n";
    }

    return 0;
}