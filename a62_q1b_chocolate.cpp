#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<ll> dp(n+5);
    vector<ll> s(k);
    dp[0] = 1;
    for (auto &e : s) cin >> e;
    for (int i=1;i<=n;i++){
        for (auto e : s){
            if (i - e >= 0)
                dp[i] += dp[i-e]%(1LL*1000003);
        }
    }
    cout << dp[n]%1000003;

    return 0;
}