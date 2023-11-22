#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> grid(n+5);
    vector<int> monpos(m);
    vector<int> monpow(m);
    for (auto &e : monpos) cin >> e;
    for (auto &e : monpow) cin >> e;
    for (int i=0;i<m;i++)
        grid[monpos[i]] += monpow[i];
    for (int _=0;_<k;_++){
        int e;
        cin >> e;
        for (int i=max(e-w,0);i<=min(e+w, n);i++){
            if (grid[i] != 0){
                grid[i]--;
                break;
            }
        }
    }
    int cnt=0;
    for (auto e : grid) cnt += e;
    cout << cnt;

    return 0;
}