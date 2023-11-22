#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt=0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    vector<int> s = v;
    sort(ALL(s));
    map<pair<int,int>, int> mp;
    for (int i=0;i<n;i++){
        if (s[i] != v[i])
            mp[{v[i], s[i]}]++;
    }
    for (int i=1;i<=3;i++){
        for (int j=i+1;j<=3;j++){
            if (mp[{i,j}] && mp[{j,i}]){
                int a = min(mp[{i,j}], mp[{j,i}]);
                mp[{i,j}] -= a;
                mp[{j,i}] -= a;
                ans += a;
            }
        }
    }
    for (auto &[k, v] : mp)
        cnt += v;
    ans += cnt*2/3;
    cout << ans;

    return 0;
}